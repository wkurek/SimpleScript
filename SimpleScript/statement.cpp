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
        (*(this->trueStatementListPtr)).evaluate(scope);
    } {
		(*(this->falseStatementListPtr)).evaluate(scope);
    }
}

void IterationStatement::evaluate(Object& scope) {
    while(this->conditionExpressionPtr->evaluate(scope)) {
		(*(this->statementsListPtr)).evaluate(scope);
    }
}

void ReturnStatement::evaluate(Object& scope) {
    throw ReturnVariable(shared_ptr<Variable>(
		new Variable(this->expressionPtr->evaluate(scope))));
}

void FunctionDeclarationStatement::evaluate(Object& scope) {
	//Check for anonymous function declaration
	if (this->functionPtr == nullptr) return;

    if(scope.hasPrimitive(*(this->identifierPtr))) scope.removePrimitive(*(this->identifierPtr));
    if(scope.hasObject(*(this->identifierPtr))) scope.removeObject(*(this->identifierPtr));

    scope.getFunction(*(this->identifierPtr)) = *(this->functionPtr);
}

Function FunctionDeclarationStatement::getFunction() {
	return *(this->functionPtr);
}

void ExpressionStatement::evaluate(Object& scope) {
	this->operationExpressionPtr->evaluate(scope);
}

void VariableDeclarationStatement::evaluate(Object& scope) {
	this->operationExpressionsListPtr->evaluate(scope);
}
