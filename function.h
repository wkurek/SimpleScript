#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "statement.h"
#include "variable.h"
#include "operation_expression.h"

class Statement;
class StatementsList;
class OperationExpression;

class ParametersList {
    list<string> parametersList;

public:
    void add(string&);
    unsigned int getSize() const;
};

class ArgumentsList {
    list<OperationExpression*> argumentsList;

public:
    ~ArgumentsList();

    void add(OperationExpression&);
    unsigned int getSize() const;
};

class Function {
    ParametersList parametersList;
    StatementsList* statementList;

public:
    friend ostream& operator<< (ostream&, Function&);

    Variable call(ArgumentsList args);
};

#endif // FUNCTION_H_INCLUDED
