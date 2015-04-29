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
  
  Variables vars;
  Variables* Engine::vars2 = &vars;
  Engine engine;
  int isInLoop = false;
  bool startLoop = false;
  bool stopLoop = false;
  
  std::vector<Exp*> loops;
  std::map<int , std::vector<Exp*> > map;

}


%expect 0



%token <int> INT 
%token <std::string> STRING
%token <std::string> STDSTRING
%type <Exp*> exp line

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

%right VAR 
%right WHILE
%right IF THEN ELSE
%right FOR EQUALS TO DO
%right STRING 
%right STDSTRING 
%left "+" "-"
%left "*" "/"
%right PV

%%
input:
  %empty
| input line  { 
                std::stringstream ss;
                std::string s;
                ss<<*$2;
                s = ss.str();
                if(s!="null"){
                  std::cout<<*$2<<std::endl;
                  vars.newExp($2);
                  vars.addExp($2);
                }
                if(stopLoop){

                }

                if(!isInLoop){
                  $2.accept(engine);
                }
              }
;

line:
  EOL       { $$ = $$=new Null(); }
| exp EOL   { $$ = $1; }
| error EOL { $$ = $$=new Null(); yyerrok; }
;

exp:
  exp "+" exp  { $$ = createBin('+',$1, $3); }
| exp "-" exp  { $$ = createBin('-',$1, $3); }
| exp "*" exp  { $$ = createBin('*',$1, $3); }
| exp "/" exp  {  Engine calc;
                  double i=(*$3)();
                  if(i){
                    $$ = createBin('/',$1, $3); 
                  }else{
                    error(@3, "division by 0");
                    YYERROR;
                  }
                }
| "(" exp ")"  { $$ = $2; }
| "(" error ")"{ $$ = createNum(777); }
| INT          { $$ = createNum($1); }
| IF exp THEN exp ELSE exp { $$ = createIf($2,$4,$6);}
| IF exp THEN exp{ $$ = createIf($2,$4);}
| FOR exp TO exp DO exp { $$ = createFor($2,$4,$4,$6);vars.newScope();vars.newVar(((Var*) $2)->name_, $2);}
| WHILE exp DO exp{ $$ = createWhile($2,$4);}
| LACO { vars.newScope(); $$=new Null(); }
| RACO { try{
    vars.deleteScope();
    $$=new Null();
  }catch(const std::string & Msg){
    error(@1, "No more scope to quit"); YYERROR;
  }
}
| VAR STRING{
  try{
    vars.newVar($2,createNum(0)); 
    $$=createVar($2,createNum(0));
  }catch(const std::string& msg){
    error(@2,msg);YYERROR;
  }
}

| VAR STRING EQUALS exp {
 try{
    vars.newVar($2,$4); 
    $$=createVar($2,$4);
  }catch(const std::string& msg){
    error(@2,msg);YYERROR;
  }
}
| STRING EQUALS exp {
  bool res = vars.hasVar($1);
  try{
    if(res){
      vars.setVar($1,$3);
      $$ = new Assignment($1,$3);
    }else{
      error(@1, "is not an existed variable"); YYERROR;
    }
  }catch(const std::string & Msg){
    error(@1, "truc de merde"); YYERROR;
  }
}
| STRING { try{
              $$ = new ShowVar(vars.getVar($1));
            } catch(const std::string & Msg){
              error(@1, "not a statement"); YYERROR;
            }
}
| STDSTRING { $$ = new StringExp($1);}
| AFFICHE {
  vars.affiche();
  $$=new Null();
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
  std::cout << Engine::vars2 << std::endl;
  std::cout << &vars << std::endl;
  unsigned nerrs = 0;
  yy::parser parser(&nerrs);
  nerrs += !!parser.parse();

  return !!nerrs;
}
