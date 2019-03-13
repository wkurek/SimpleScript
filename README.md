# SimpleScript

##EBNF
Formal language grammar specification.

```
Program                         = StatementsList
                                ;

StatementsList                  = (*empty program*)
                                | StatementsList, Statement
                                | Statement
                                ;

Statement                       = ExpressionStatement
                                | VariableDeclarationStatement
                                | FunctionDeclarationStatement
                                | ReturnStatement
                                | IterationStatement
                                | ConditionalStatement
                                | Print
                                ;

ExpressionStatement             = AssignmentExpression
                                | OperationExpression
                                | FunctionCallExpression
                                ;

AssignmentStatement             = Idefntifier, "=", OperationExpression
                                | Idefntifier, "=", FunctionDeclarationStatement
                                | Idefntifier, "=", ObjectLiteral
                                ;

ObjectLiteral                   = "{", [(PropertyNameAndValue, {",", PropertyNameAndValue})], "}"
                                ;

PropertiesNamesAndValues        = (*no properties*)
                                | PropertiesNamesAndValues, PropertyNameAndValue
                                | PropertyNameAndValue
                                ;

PropertyNameAndValue            = PropertyName, ":", OperationExpression
                                | PropertyName, ":", FunctionDeclarationStatement
                                | PropertyName, ":", ObjectLiteral
                                | PropertyName, ":", Idefntifier
                                ;

OperationExpression             = "(", OperationExpression, ")"
                                | Idefntifier
                                | INTEGER
                                | BOOLEAN
                                | STRING
                                | OperationExpression, "<", OperationExpression
                                | OperationExpression, "<=", OperationExpression
                                | OperationExpression, ">", OperationExpression
                                | OperationExpression, ">=", OperationExpression
                                | OperationExpression, "==", OperationExpression
                                | OperationExpression, "!=", OperationExpression
                                | OperationExpression, "+", OperationExpression
                                | OperationExpression, "-", OperationExpression
                                | OperationExpression, "*", OperationExpression
                                | OperationExpression, "/", OperationExpression
                                | "++", OperationExpression
                                | "--", OperationExpression
                                | FunctionCallExpression
                                ;

FunctionCallExpression          = Idefntifier, "(", ArgumentsList, ")"
                                ;

ArgumentsList                   = (*empty arguments list*)
                                | ArgumentsList, Argument
                                | Argument
                                ;

Argument                        = OperationExpression
                                | INTEGER
                                | BOOLEAN
                                | STRING
                                ;

VariableDeclarationStatement    = VAR, VariableDeclarationList 
                                ;

VariableDeclarationList         = VariableDeclarationList, VariableDeclaration
                                | VariableDeclaration
                                ;

VariableDeclaration             = AssignmentStatement
                                ;

FunctionDeclarationStatement    = FUNCTION, [Idefntifier], "(", ParametersList, ")", FunctionBody
                                ;

ParametersList                  = (*empty parameters list*)
                                | ParametersList, Idefntifier
                                | Idefntifier
                                ;

FunctionBody                    = "{", StatementsList, "}"
                                ;

ReturnStatement                 = RETURN, OperationExpression;

IterationStatement              = WHILE, "(", OperationExpression, ")", Block;

ConditionalStatement            = IF, "(", OperationExpression, ")", Block, ELSE, Block
                                ;

Block                           = "{", StatementsList, "}"
                                | Statement
                                ;

Print                           = PRINT, "(", OperationExpression, ")";

Idefntifier                     = Idefntifier, ".", Idefntifier
                                | Idefntifier, "[", Idefntifier, "]"
                                | IDENTIFIER
                                ;

IDENTIFIER                      = [_a-zA-Z$]([_0-9a-zA-Z])*
                                ;

INTEGER                         = [0-9]+
                                ;

STRING                          = "(.)*"
                                ;

BOOLEAN                         = "true"
                                | "false";


PRINT                           = "print"
                                ;

IF                              = "if"
                                ;

ELSE                            = "else"
                                ;

WHILE                           = "while"
                                ;

FUNCTION                        = "function"
                                ;

VAR                             = "var"
                                ;

RETURN                          = "return"
                                ;
```