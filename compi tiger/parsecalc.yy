%defines
%error-verbose
%debug
%language "c++"
%define api.token.prefix {TOK_}
%define api.value.type variant
%locations
%parse-param { unsigned* nerrs }


%code provides
{
#define YY_DECL                                 \
   yy::parser::token_type yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc)
  YY_DECL;
}

%code requires // .hh
{
  #include "Exp.hh"
}

%code top // .cc
{
  #include "Exp.hh"
  #include <stdio.h>
  #include <stdlib.h>
  #include <map>
  #include <vector>
  #include "scancalc.cc"
  
  Ressources vars;
  Ressources* Engine::vars2 = &vars;
  Ressources* Calculator::vars2 = &vars;
  Ressources* VisExp::vars2 = &vars;
  Engine engine;

  int LetExp::totalNum = -1;

  bool isInHead = false;
  bool isInBody = true;
  bool isNewScope = false;
  bool isInFunction = false;
  bool isInClass = false;
  std::vector<Sequence*> vector;
  FILE* in = NULL;
  int isInside = 0;
  FILE* truc = stdin;
  std::vector<Function*> Driver::f;
  std::vector<Exp*> Driver::v;
  Driver driver;
}


%expect 0



%token <int> INT 
%token <std::string> STRING
%token <std::string> STDSTRING
%token <char*> FILENAME
%type <Exp*> exp line operation
%type <Sequence*> exps
%type <Sequence2*> truc
%type <std::vector<Exp*> *> truc2

%printer { yyo << $$; } <Exp*>

%token
  LPAREN "("
  MINUS "-"
  PLUS "+"
  RPAREN ")"
  SLASH "/"
  STAR  "*"
  PV ";"
  EOL "end of line"
  EOF 0 "end of file"
  IF "if"
  ELSE "else"
  FOR "for"
  FROM "from"
  TO "to"
  DO "do"
  WHILE "while"
  LACO "{"
  RACO "}"
  THEN "then"
  VAR "var"
  EQUALS "="
  AFFICHE "affiche"
  LET "let"
  IN "in"
  END "end"
  VIR ","
  IMPORT "import"
  CLASS "class"
  FUNCTION "function"
  METHOD "method"
  DP ":"
  AND "&"
  OR "|"
%right STRING 
%right "(" ")"
%right VAR 
%right IF THEN ELSE
%right WHILE FOR TO DO
%right STDSTRING 
%nonassoc EQUALS
%right "|"
%right "&"
%left "+" "-"
%left "*" "/"
%right PV VIR

%%
input:
%empty
| input line  { 

                std::stringstream ss;
                std::string s;
                ss<<*$2;
                s = ss.str();
                if(s!="null"){
                  if(isNewScope){
                    if(isInside>0){
                      if(isInBody) vars.addExpInBody($2);
                      if(isInHead) vars.addExpInHead($2);
                    }
                  }
                  if(isInside==0) vars.addExpInGeneralScope($2);
                  if(isNewScope) isInside++;
                  isNewScope=false;
                  try{
                    $2->accept(engine);
                  }catch(const std::string& m){
                    error(@2, m); yyerrok;
                  }
                }
              }
;

line:
  EOL       { $$ = $$=Driver::createNull(); }
| exp EOL   { $$ = $1; }
| error EOL { $$ = $$=Driver::createNull(); yyerrok; }
;



exp:
operation { $$ = $1; }
| "(" exps ")" { $$ = $2; }
| "(" error ")"{ $$ = Driver::createNum(777); }
| INT          { $$ = Driver::createNum($1); }
| IF exp THEN exp ELSE exp { $$ = Driver::createIfExp($2,$4,$6);}
| IF exp THEN exp{ $$ = Driver::createIfExp($2,$4);}
| FOR exp TO exp DO exp { $$ = Driver::createForExp($2,$4,$4,$6);}
| WHILE exp DO exp{ $$ = Driver::createWhileExp($2,$4);}
| VAR STRING EQUALS exp { $$=Driver::createVar($2,$4); }
| STRING EQUALS exp { $$ = Driver::createAssignment($1,$3); }
| STRING { $$ = Driver::createShowVar($1); }
| STDSTRING { $$ = Driver::createStringExp($1);}
| AFFICHE {
  vars.affiche();
  $$=Driver::createNull();
}
| AFFICHE STRING{
  VisExp vis;
  Exp* e = vars.getVar($2)->accept(vis);
  if(e->type=="int") std::cout<<((Num*) e)->val_<<std::endl;
  if(e->type=="string") std::cout<<((StringExp*) e)->val_<<std::endl;

  $$=Driver::createNull();
}
| LET { if(isInBody){
          $$ = Driver::createLetExp();
          vars.newScope((LetExp*)$$);
          isInBody=false;
          isInHead=true;
          isNewScope = true;
        } else{
          error(@1, "let can only be used in a body"); YYERROR;
        }
}
| END { 
  try{
          if(isInBody){
            vars.deleteScope();
            $$ = Driver::createNull();
          }else{
            error(@1, "end can only be used in a body"); YYERROR;
          }
        }catch( const std::string msg){
          error(@1, "no more scope to quit"); YYERROR;
        }
}
| IN {
  if(isInHead){
    $$ = Driver::createNull();
    isInBody=true;
    isInHead=false;
  }else{
    error(@1, "in can only be used in a head"); YYERROR;
  }
}
| CLASS STRING{
  $$=Driver::createNull();
}
| FUNCTION STRING "(" truc ")" EQUALS exp {
  std::string* s = new std::string($2);
  Function* f = Driver::createFunction(*s,"null",$4->names,$4->types,$7);
  Exp * e = Driver::createFunctionExp(f);
  $$ = Driver::createFunctionExp(f);
}
| FUNCTION STRING "(" ")" EQUALS exp{
  $$ = Driver::createFunctionExp(Driver::createFunction($2,"null",{},{},$6));
}
| METHOD STRING "(" exps ")" EQUALS exp{
  $$=Driver::createNull();
}
| METHOD STRING "(" ")" EQUALS exp{
  $$=Driver::createNull();
}
| STRING "(" truc2 ")"{
  $$ = Driver::createExecuteFunction($1,*$3);
}
| STRING "(" ")"{
  $$ = Driver::createExecuteFunction($1,{});

}

;

operation:
  exp "+" exp  { $$ = Driver::createBin('+',$1, $3); }
| exp "-" exp  { $$ = Driver::createBin('-',$1, $3); }
| exp "*" exp  { $$ = Driver::createBin('*',$1, $3); }
| exp "/" exp  { $$ = Driver::createBin('/',$1, $3); }
| exp "&" exp  { $$ = Driver::createBin('&',$1, $3); }
| exp "|" exp  { $$ = Driver::createBin('|',$1, $3); }
;




exps:
exp {$$ = (Sequence*) Driver::createSequence($1);}
| exps PV exp {$1->vector.push_back($3); $$ = $1;}
;

truc:
STRING DP STRING {
  $$ = (Sequence2*) Driver::createSequence2();
  $$->push($1,$3);
}
| truc VIR STRING DP STRING{
  $1->push($3,$5);
  $$=$1;
}
;

truc2:
exp{
  $$ = new std::vector<Exp*>(); 
  $$->push_back($1);
}
| truc2 VIR exp{
  $1->push_back($3);
  $$=$1;
}
;




%%
void yy::parser::error(const location_type& loc, const std::string& msg)
{
  std::cerr <<  loc;
  std::cerr << ": " << msg << "\n";
  *nerrs += 1;
}



int main()
{
  //yydebug = !!getenv("YYDEBUG");
  unsigned nerrs =0;
  /*
  FILE* f = fopen("t.t","r");
  #define YY_STDINIT
  yyset_in(f);
  yyset_out(stdout);
  */
  yy::parser parser(&nerrs);
  nerrs += !!parser.parse();

  return !!nerrs;
}
