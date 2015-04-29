/* Prologue. */
%option noyywrap
%{
#include "parsecalc.hh"

# define YY_USER_ACTION                         \
  yylloc->end.column += yyleng;

%}
%%
%{
  yylloc->step();
%}
"+"         return yy::parser::token::TOK_PLUS;
"-"         return yy::parser::token::TOK_MINUS;
"*"         return yy::parser::token::TOK_STAR;
"/"         return yy::parser::token::TOK_SLASH;
"("         return yy::parser::token::TOK_LPAREN;
")"         return yy::parser::token::TOK_RPAREN;
";"         return yy::parser::token::TOK_PV;
"if"		return yy::parser::token::TOK_IF;
"for"		return yy::parser::token::TOK_FOR;
"from"		return yy::parser::token::TOK_FROM;
"to"		return yy::parser::token::TOK_TO;
"do"		return yy::parser::token::TOK_DO;
"else"		return yy::parser::token::TOK_ELSE;
"while"		return yy::parser::token::TOK_WHILE;
"then"		return yy::parser::token::TOK_THEN;
"var"		return yy::parser::token::TOK_VAR;
"="			return yy::parser::token::TOK_EQUALS;
"let"		return yy::parser::token::TOK_LET;
"in"		return yy::parser::token::TOK_IN;
"end"		return yy::parser::token::TOK_END;
","			return yy::parser::token::TOK_VIR;
"{"			return yy::parser::token::TOK_LACO;
"import"	return yy::parser::token::TOK_IMPORT;
"}"			return yy::parser::token::TOK_RACO;
"affiche"	return yy::parser::token::TOK_AFFICHE;
"\""[a-zA-Z][a-zA-Z0-9]+"\"" yylval->build<std::string>(yytext); return yy::parser::token::TOK_STDSTRING;
[a-zA-Z][a-zA-Z0-9]+	yylval->build<std::string>(yytext); return yy::parser::token::TOK_STRING;
[a-zA-Z]	yylval->build<std::string>(yytext); return yy::parser::token::TOK_STRING;
[0-9]+    	yylval->build<int>(strtol(yytext, 0,10));return yy::parser::token::TOK_INT;
"."			std::cerr << "error: invalid character: "<<yytext;	
" "+        yylloc->step(); continue;
"\n"        yylloc->end.line += 1; yylloc->end.column = 1; yylloc->step(); return yy::parser::token::TOK_EOL;
[a-zA-Z]"."[a-zA-Z]+ yylval->build<char*>(yytext); return yy::parser::token::TOK_FILENAME;
[a-zA-Z][a-zA-Z0-9]+"."[a-zA-Z]+ yylval->build<char*>(yytext); return yy::parser::token::TOK_FILENAME;
<<EOF>>		yyin=stdin; return yy::parser::token::TOK_EOF;

%%
/* Epilogue.  */
