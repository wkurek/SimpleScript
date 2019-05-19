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
    } else if (this->falseStatementListPtr != nullptr) {
		(*(this->falseStatementListPtr)).evaluate(scope);
    }
}

void IterationStatement::evaluate(Object& scope) {
    while(this->conditionExpressionPtr->evaluate(scope)) {
		(*(this->statementsListPtr)).evaluate(scope);
    }
}

void ReturnStatement::evaluate(Object& scope) {
	std::shared_ptr<Variable> variablePtr;

	if (this->expressionPtr == nullptr) {
		variablePtr = std::make_shared<Variable>();
	}
	else {
		variablePtr = std::make_shared<Variable>(
			this->expressionPtr->evaluate(scope));
	}


    throw ReturnVariable(variablePtr);
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

void LogStatement::evaluate(Object& scope) {
	cout << this->identifierExpressionPtr->evaluate(scope) << endl;
}
