%option noyywrap
%option yylineno

%{
    #include <iostream>
    #include <string>
    #include <sstream>

	#include "primitive.h"
	#include "identifier.h"
	#include "object.h"
	#include "function.h"
	#include "variable.h"
	#include "exception.h"
	#include "operation_expression.h"
	#include "statement.h"
	#include "assignment.h"

    #include "SimpleScript.tab.h"


    extern int yylex();
    extern void yyerror(const char*, char);
%}

identifier [_a-zA-Z$]([_0-9a-zA-Z])*
integer [0-9]+
float [0-9]+\.[0-9]+
boolean true|false
string \"(\\.|[^"\\])*\"

%%

"\/\/"[^\r\n]*              { /* single line comment, ignore */cout << "single line comment, ignore" << endl; }
"/*"([^*]|(\*+[^*/]))*\*+\/ { /* multiple line comment, ignore */ cout << "multiple line comment, ignore" << endl; }
[ \t\n\r;]                  { /* whitespace, ignore */  }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return ASTERISK; }
"/"                         { return SLASH; }
"++"                        { return INC; }
"--"                        { return DEC; }
"!"                         { return NOT; }
"("                         { return OPEN_PARENTHESIS; }
")"                         { return CLOSE_PARENTHESIS; }
"["                         { return OPEN_BRACKET; }
"]"                         { return CLOSE_BRACKET; }
"="                         { return ASSIGN; }
"=="                        { return EQUAL; }
"!="                        { return NOT_EQUAL; }
"<"                         { return LESS_THAN; }
">"                         { return GREATER_THAN; }
"<="                        { return LESS_EQUAL_THAN; }
">="                        { return GREATER_EQUAL_THAN; }
"||"                        { return OR; }
"&&"                        { return AND; }
":"                         { return COLON; }
","                         { return COMMA; }
"."                         { return DOT; }
"{"                         { return OPEN_BRACE; }
"}"                         { return CLOSE_BRACE; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"while"                     { return WHILE; }
"var"                       { return VAR; }
"function"                  { return FUNCTION_T; }
"return"                    { return RETURN; }

{integer}       { istringstream(string(yytext)) >> yylval.integerVal; return INTEGER_T; }

{float}         { istringstream(string(yytext)) >> yylval.floatVal; return FLOAT_T; }

{boolean}       { istringstream(string(yytext)) >> boolalpha >> yylval.booleanVal; return BOOLEAN_T; }

{identifier}    { yylval.stringVal = _strdup(yytext); return IDENTIFIER; }

{string}        { yylval.stringVal = _strdup(yytext); return STRING; }

.               { yyerror("undefined token", yytext[0]); yyterminate(); }

%%