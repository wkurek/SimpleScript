#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <stdexcept>
using namespace std;

#include "statement.h"
#include "variable.h"
#include "operation_expression.h"
#include "object.h"
#include "exception.h"

class Statement;
class StatementsList;
class OperationExpression;

class ParametersList {
    list<string> parametersList;

public:
    void add(string&);
    list<string>::iterator begin();
    list<string>::iterator end();

    size_t size() const;
};

class ArgumentsList {
    list<shared_ptr<OperationExpression>> argumentsList;

public:
    void add(shared_ptr<OperationExpression>);
    list<shared_ptr<OperationExpression>>::iterator begin();
    list<shared_ptr<OperationExpression>>::iterator end();

	size_t size() const;
};

class Function {
    shared_ptr<ParametersList> parametersListPtr;
    shared_ptr<StatementsList> statementListPtr;

    Object generateLocalScope(Object, ArgumentsList);

public:
    Function() : parametersListPtr(nullptr), statementListPtr(nullptr) {}

    Function(shared_ptr<ParametersList> plPtr, shared_ptr<StatementsList> slPtr)
        : parametersListPtr(move(plPtr)), statementListPtr(move(slPtr)) {}

    friend ostream& operator<< (ostream&, Function&);

    Variable call(Object, ArgumentsList);
};

#endif // FUNCTION_H_INCLUDED
