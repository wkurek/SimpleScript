%error-verbose

%{
    #include <iostream>

    extern int yylex(void);
    extern int yylineno;
    extern int yyparse();

    void yyerror(const char* s) {}
    void yyerror(const char* s, char c) {}
%}

%union {
    int integerVal;
    float floatVal;
    bool booleanVal;
    char* stringVal;
}

%token<integerVal> INTEGER "INTEGER"
%token<floatVal> FLOAT "FLOAT"
%token<bool> BOOLEAN "BOOLEAN"
%token<stringVal> STRING "STRING"
%token<stringVal> IDENTIFIER "IDENTIFIER"
%token INC                  "++"
%token DEC                  "--"
%token NOT                  "!"
%token OPEN_PARENTHESIS     "("
%token CLOSE_PARENTHESIS    ")"
%token OPEN_BRACKET         "["
%token CLOSE_BRACKET        "]"
%token ASSIGN               "="
%token COLON                ":"
%token COMMA                ","
%token DOT                  "."
%token OPEN_BRACE           "{"
%token CLOSE_BRACE          "}"
%token IF                   "if"
%token ELSE                 "else"
%token WHILE                "while"
%token VAR                  "var"
%token FUNCTION             "function"
%token RETURN               "return"

%left AND OR
%left LESS_THAN LESS_EQUAL_THAN GREATER_THAN GREATER_EQUAL_THAN EQUAL NOT_EQUAL
%left PLUS MINUS
%left ASTERISK SLASH


%%
program                         : statements_list {}
                                ;

statements_list                 : /* empty statements list */ {}
                                | statements_list statement {}
                                | statement {}
                                ;

statement                       : expression_statement {}
                                | variable_declaration_statement {}
                                | function_declaration_statement {}
                                | return_statement {}
                                | iteration_statement {}
                                | conditional_statement {}
                                ;

expression_statement            : assignment_expression {}
                                | operation_expression {}
                                | function_call_expression {}
                                ;

assignment_expression           : identifier ASSIGN operation_expression {}
                                | identifier ASSIGN function_declaration_statement {}
                                | identifier ASSIGN object_literal {}
                                ;

object_literal                  : OPEN_BRACE properties_names_and_values CLOSE_BRACE {}
                                ;

properties_names_and_values     : /* empty object */ {}
                                | properties_names_and_values COMMA property_name_and_value {}
                                | property_name_and_value {}
                                ;

property_name_and_value         : STRING COLON operation_expression {}
                                | STRING COLON function_declaration_statement {}
                                | STRING COLON object_literal {}
                                ;

operation_expression            : OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS {}
                                | identifier {}
                                | INTEGER {}
                                | FLOAT {}
                                | BOOLEAN {}
                                | STRING {}
                                | operation_expression AND operation_expression {}
                                | operation_expression OR operation_expression {}
                                | operation_expression LESS_THAN operation_expression {}
                                | operation_expression LESS_EQUAL_THAN operation_expression {}
                                | operation_expression GREATER_THAN operation_expression {}
                                | operation_expression GREATER_EQUAL_THAN operation_expression {}
                                | operation_expression EQUAL operation_expression {}
                                | operation_expression NOT_EQUAL operation_expression {}
                                | operation_expression PLUS operation_expression {}
                                | operation_expression MINUS operation_expression {}
                                | operation_expression ASTERISK operation_expression {}
                                | operation_expression SLASH operation_expression {}
                                | NOT operation_expression {}
                                | INC operation_expression {}
                                | DEC operation_expression {}
                                | DEC function_call_expression {}
                                ;

function_call_expression        : identifier OPEN_PARENTHESIS arguments_list CLOSE_PARENTHESIS {}
                                ;

arguments_list                  : /* empty arguments list */ {}
                                | arguments_list COMMA argument {}
                                | argument {}
                                ;

argument                        : operation_expression {}
                                ;

variable_declaration_statement  : VAR variable_declaration_list {}
                                ;

variable_declaration_list       : variable_declaration_list COMMA variable_declaration {}
                                | variable_declaration {}
                                ;

variable_declaration            : assignment_expression {}
                                | IDENTIFIER {}
                                ;

function_declaration_statement  : FUNCTION IDENTIFIER OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body {}
                                | FUNCTION OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body {}
                                ;

parameters_list                 : /* empty parameters list */ {}
                                | parameters_list COMMA IDENTIFIER {}
                                | IDENTIFIER {}
                                ;

function_body                   : OPEN_BRACE statements_list CLOSE_BRACE {}
                                ;

return_statement                : RETURN operation_expression {}
                                ;

iteration_statement             : WHILE OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block {}
                                ;

conditional_statement           : IF OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block ELSE block {}
                                ;

block                           : OPEN_BRACE statements_list CLOSE_BRACE {}
                                | statement {}
                                ;

identifier                      : identifier DOT identifier {}
                                | identifier OPEN_BRACKET INTEGER CLOSE_BRACKET {}
                                | identifier OPEN_BRACKET STRING CLOSE_BRACKET {}
                                | IDENTIFIER {}
                                ;


%%

int main(int argc, char** argv) {
   yyparse();
}