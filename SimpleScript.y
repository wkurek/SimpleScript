%error-verbose

%{
    #include <iostream>
%}

%union {
    int integerVal;
    float floatVal;
    bool booleanVal;
    char* stringVal;
}

%token<integerVal> INTEGER "integer"
%token<floatVal> FLOAT "float"
%token<bool> BOOLEAN "boolean"
%token<stringVal> STRING "string"
%token<stringVal> IDENTIFIER "identifier"
%token PLUS                 "+"
%token MINUS                "-"
%token ASTERISK             "*"
%token SLASH                "/"
%token OPEN_PARENTHESIS     "("
%token CLOSE_PARENTHESIS    ")"
%token OPEN_BRACKET         "["
%token CLOSE_BRACKET        "]"
%token ASSIGN               "="
%token EQUAL                "=="
%token NOT_EQUAL            "!="
%token LESS_THAN            "<"
%token GREATER_THAN         ">"
%token LESS_EQUAL_THAN      "<="
%token GREATER_EQUAL_THAN   ">="
%token COLON                ":"
%token COMMA                ","
%token OPEN_BRACE           "{"
%token CLOSE_BRACE          "}"
%token IF                   "if"
%token ELSE                 "else"
%token WHILE                "while"
%token VAR                  "var"
%token FUNCTION             "function"
%token RETURN               "return"