#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"
#include "operation_expression.h"

void StatementsList::add(shared_ptr<Statement> statementPtr) {
    this->statements.push_back(statementPtr);
}

void StatementsList::evaluate(Object scope) {
    for(auto it = this->statements.begin(); it != this->statements.end(); ++it) {
        (*it)->evaluate(scope);
    }
}

void ConditionalStatement::evaluate(Object scope) {
    if(this->conditionExpressionPtr->evaluate(scope)) {
        this->trueStatementList.evaluate(scope);
    } {
        this->trueStatementList.evaluate(scope);
    }
}

void IterationStatement::evaluate(Object scope) {
    while(this->conditionExpressionPtr->evaluate(scope)) {
        this->statementsList.evaluate(scope);
    }
}
