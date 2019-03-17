%error-verbose

%{
    #include <iostream>
    using namespace std;

    extern int yylex(void);
    extern int yylineno;
    extern int yyparse();

    extern FILE *yyin;

    bool errorReported = false;

    void yyerror(const char* s) {
      if(!errorReported) {
         cerr << "ERROR:\t at line " << yylineno << ":\t" << s << endl;
      }
    }

    void yyerror(const char* s, char c) {
      cerr << "ERROR:\tat line " << yylineno << ": " << s << " \"" << c << "\"" << endl;
      errorReported = true;
    }
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
program                         : statements_list { cout<< "---- END ----" << endl;}
                                ;

statements_list                 : /* empty statements list */ {cout<< "empty statements_list" << endl;}
                                | statements_list statement {cout<< "statements_list statement" << endl;}
                                | statement {cout<< "statement" << endl;}
                                ;

statement                       : expression_statement { cout<< "expression_statement" << endl; }
                                | variable_declaration_statement { cout<< "variable_declaration_statement" << endl; }
                                | function_declaration_statement { cout<< "function_declaration_statement" << endl; }
                                | return_statement { cout<< "return_statement" << endl; }
                                | iteration_statement { cout<< "iteration_statement" << endl; }
                                | conditional_statement { cout<< "conditional_statement" << endl; }
                                ;

expression_statement            : assignment_expression { cout<< "program start" << endl; }
                                | operation_expression { cout<< "program start" << endl; }
                                ;

assignment_expression           : identifier ASSIGN operation_expression { cout<< "assignment_expression operation_expression" << endl; }
                                | identifier ASSIGN function_declaration_statement { cout<< "identifier ASSIGN function_declaration_statement" << endl; }
                                | identifier ASSIGN object_literal { cout<< "identifier ASSIGN object_literal" << endl; }
                                ;

object_literal                  : OPEN_BRACE properties_names_and_values CLOSE_BRACE { cout<< "object_literal" << endl; }
                                ;

properties_names_and_values     : /* empty object */ { cout<< "empty properties_names_and_values" << endl; }
                                | properties_names_and_values COMMA property_name_and_value { cout<< "properties_names_and_values COMMA property_name_and_value" << endl; }
                                | property_name_and_value { cout<< "program start" << endl; }
                                ;

property_name_and_value         : IDENTIFIER COLON operation_expression { cout<< "program start" << endl; }
                                | IDENTIFIER COLON function_declaration_statement { cout<< "program start" << endl; }
                                | IDENTIFIER COLON object_literal { cout<< "program start" << endl; }
                                ;

operation_expression            : OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS { cout<< "( operation_expression )" << endl; }
                                | INTEGER { cout<< "integer " << $1 <<endl; }
                                | FLOAT { cout<< "FLOAT "  << endl; }
                                | BOOLEAN { cout<< "BOOLEAN "  << endl; }
                                | STRING { cout<< "STRING " << $1 << endl; }
                                | identifier { cout<< "identifier" << endl; }
                                | operation_expression AND operation_expression { cout<< "&&" << endl; }
                                | operation_expression OR operation_expression { cout<< "||" << endl; }
                                | operation_expression LESS_THAN operation_expression { cout<< "<" << endl; }
                                | operation_expression LESS_EQUAL_THAN operation_expression { cout<< "<=" << endl; }
                                | operation_expression GREATER_THAN operation_expression { cout<< ">" << endl; }
                                | operation_expression GREATER_EQUAL_THAN operation_expression { cout<< ">=" << endl; }
                                | operation_expression EQUAL operation_expression { cout<< "==" << endl; }
                                | operation_expression NOT_EQUAL operation_expression { cout<< "!=" << endl; }
                                | operation_expression PLUS operation_expression { cout<< "+" << endl; }
                                | operation_expression MINUS operation_expression { cout<< "-" << endl; }
                                | operation_expression ASTERISK operation_expression { cout<< "*" << endl; }
                                | operation_expression SLASH operation_expression { cout<< "/" << endl; }
                                | NOT operation_expression { cout<< "!" << endl; }
                                | INC operation_expression { cout<< "++" << endl; }
                                | DEC operation_expression { cout<< "--" << endl; }
                                | function_call_expression { cout<< "program start" << endl; }
                                ;

function_call_expression        : identifier OPEN_PARENTHESIS arguments_list CLOSE_PARENTHESIS { cout<< "function_call_expression" << endl; }
                                ;

arguments_list                  : /* empty arguments list */ { cout<< "program start" << endl; }
                                | arguments_list COMMA argument { cout<< "arguments_list COMMA argument" << endl; }
                                | argument { cout<< "argument" << endl; }
                                ;

argument                        : operation_expression { cout<< "operation_expression" << endl; }
                                ;

variable_declaration_statement  : VAR variable_declaration_list { cout<<"VAR variable declaration"<<endl;}
                                ;

variable_declaration_list       : variable_declaration_list COMMA variable_declaration { cout<< "variable_declaration_list COMMA" << endl; }
                                | variable_declaration { cout<< "variable_declaration in variable_declaration_list" << endl; }
                                ;

variable_declaration            : assignment_expression { cout<< "variable_declaration =" << endl; }
                                | IDENTIFIER { cout<< "variable_declaration id" << $1 << endl; }
                                ;

function_declaration_statement  : FUNCTION IDENTIFIER OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body { cout<< "program start" << endl; }
                                | FUNCTION OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body { cout<< "program start" << endl; }
                                ;

parameters_list                 : /* empty parameters list */ { cout<< "program start" << endl; }
                                | parameters_list COMMA IDENTIFIER { cout<< "program start" << endl; }
                                | IDENTIFIER { cout<< "program start" << endl; }
                                ;

function_body                   : OPEN_BRACE statements_list CLOSE_BRACE { cout<< "program start" << endl; }
                                ;

return_statement                : RETURN operation_expression { cout<< "return_statement" << endl; }
                                ;

iteration_statement             : WHILE OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block { cout<< "iteration_statement" << endl; }
                                ;

conditional_statement           : IF OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block ELSE block { cout<< "conditional_statement" << endl; }
                                ;

block                           : OPEN_BRACE statements_list CLOSE_BRACE { cout<< "{ statements_list }" << endl; }
                                | statement { cout<< "program start" << endl; }
                                ;

identifier                      : identifier DOT identifier { cout<< "program start" << endl; }
                                | identifier OPEN_BRACKET INTEGER CLOSE_BRACKET { cout<< "program start" << endl; }
                                | identifier OPEN_BRACKET STRING CLOSE_BRACKET { cout<<" [] " << $3 << endl; }
                                | IDENTIFIER { cout<< "IDENTIFIER! " << $1 << endl; }
                                ;


%%

int main(int argc, char** argv) {
  if(argc > 1) {
    yyin = fopen(argv[1], "r");

    if(yyin == NULL) {
      cerr << "ERROR:\tcould not open file \"" << argv[1] << "\" for reading." << endl;
      return 1;
    }

    int parseResult = yyparse();
    cout << "result:\t" << parseResult << endl;
  }
}