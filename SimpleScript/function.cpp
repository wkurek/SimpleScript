#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <stdexcept>
using namespace std;

#include "function.h"
#include "statement.h"
#include "variable.h"
#include "operation_expression.h"
#include "object.h"

void ParametersList::add(string& str) {
    this->parametersList.push_back(str);
}

list<string>::iterator ParametersList::begin() {
    return this->parametersList.begin();
}

list<string>::iterator ParametersList::end() {
    return this->parametersList.end();
}

size_t ParametersList::size() const {
    return this->parametersList.size();
}

void ArgumentsList::add(shared_ptr<OperationExpression> oex) {
    this->argumentsList.push_back(oex);
}


list<shared_ptr<OperationExpression>>::iterator ArgumentsList::begin() {
    return this->argumentsList.begin();
}

list<shared_ptr<OperationExpression>>::iterator ArgumentsList::end() {
    return this->argumentsList.end();
}

size_t ArgumentsList::size() const {
    return this->argumentsList.size();
}


ostream& operator<< (ostream& out, Function& fun) {
    return out << "function";
}

Object Function::generateLocalScope(Object parentScope, ArgumentsList args) {
    Object localScope(parentScope);

    if(args.size() < this->parametersListPtr->size()) {
        throw invalid_argument("not enought params passed to function");
    }

    list<shared_ptr<OperationExpression>>::iterator argIt = args.begin();
    for(auto paramIt = this->parametersListPtr->begin();
        paramIt != this->parametersListPtr->end();
        ++paramIt, ++argIt) {

        Variable var = (*argIt)->evaluate(parentScope);
        Identifier id = Identifier(*paramIt);

        if(var.isPrimitive()) {
            localScope.getPrimitive(id) = var.getPrimitive();
        } else if(var.isObject()) {
            localScope.getObject(id) = var.getObject();
        } else if(var.isFunction()) {
            localScope.getFunction(id) = var.getFunction();
        }
    }

    return localScope;
}

Variable Function::call(Object parentScope, ArgumentsList args) {
    Object localScope = generateLocalScope(parentScope, args);

    try {
        this->statementListPtr->evaluate(localScope);
    } catch (ReturnVariable returnVariable) {
        return returnVariable.getVariable();
    }

    return Variable();
}

