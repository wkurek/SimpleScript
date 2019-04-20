#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "statement.h"
#include "object.h"
#include "operation_expression.h"
#include "exception.h"
#include "variable.h"

void StatementsList::add(shared_ptr<Statement> statementPtr) {
    this->statements.push_back(statementPtr);
}

void StatementsList::evaluate(Object& scope) {
    for(auto it = this->statements.begin(); it != this->statements.end(); ++it) {
        (*it)->evaluate(scope);
    }
}

void ConditionalStatement::evaluate(Object& scope) {
    if(this->conditionExpressionPtr->evaluate(scope)) {
        this->trueStatementList.evaluate(scope);
    } {
        this->trueStatementList.evaluate(scope);
    }
}

void IterationStatement::evaluate(Object& scope) {
    while(this->conditionExpressionPtr->evaluate(scope)) {
        this->statementsList.evaluate(scope);
    }
}

void ReturnStatement::evaluate(Object& scope) {
    Variable *var = new Variable(this->expressionPtr->evaluate(scope));

    throw ReturnVariable(make_shared<Variable>(var));
}

void FunctionDeclarationStatement::evaluate(Object& scope) {
    if(scope.hasPrimitive(this->identifier)) scope.removePrimitive(this->identifier);
    if(scope.hasObject(this->identifier)) scope.removeObject(this->identifier);

    scope.getFunction(this->identifier) = *(this->functionPtr);
}

void ExpressionStatement::evaluate(Object& scope) {
	this->operationExpressionPtr->evaluate(scope);
}
