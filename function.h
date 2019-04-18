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
    shared_ptr<ParametersList> parametersListPtr;
    shared_ptr<StatementsList> statementListPtr;

public:
    Function() : parametersListPtr(nullptr), statementListPtr(nullptr) {}

    Function(shared_ptr<ParametersList> plPtr, shared_ptr<StatementsList> slPtr)
        : parametersListPtr(move(plPtr)), statementListPtr(move(slPtr)) {}

    friend ostream& operator<< (ostream&, Function&);

    Variable call(ArgumentsList args);
};

#endif // FUNCTION_H_INCLUDED
