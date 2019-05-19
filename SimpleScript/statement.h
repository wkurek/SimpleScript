#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"
#include "operation_expression.h"
#include "exception.h"
#include "function.h"

class Object;
class Function;
class OperationExpression;
class OperationExpressionsList;
class IdentifierExpression;

class Statement {
public:
    virtual void evaluate(Object&) = 0;
};

class StatementsList {
    list<shared_ptr<Statement>> statements;

public:
	void evaluate(Object&);

    void add(shared_ptr<Statement>);
};

class ConditionalStatement : public Statement {
    shared_ptr<OperationExpression> conditionExpressionPtr;

	shared_ptr<StatementsList> trueStatementListPtr;
	shared_ptr<StatementsList> falseStatementListPtr;

public:
    ConditionalStatement(shared_ptr<OperationExpression> oePtr,
		shared_ptr<StatementsList> trueStmtListPtr, shared_ptr<StatementsList> falseStmtListPtr)
            : conditionExpressionPtr(move(oePtr)), trueStatementListPtr(move(trueStmtListPtr)),
			falseStatementListPtr(move(falseStmtListPtr)) {}

    ConditionalStatement(shared_ptr<OperationExpression> oePtr, shared_ptr<StatementsList> trueStmtListPtr)
        : conditionExpressionPtr(move(oePtr)), trueStatementListPtr(move(trueStmtListPtr)), falseStatementListPtr(nullptr) {}

	virtual void evaluate(Object&);
};

class IterationStatement : public Statement {
    shared_ptr<OperationExpression> conditionExpressionPtr;
	shared_ptr<StatementsList> statementsListPtr;

public:
    IterationStatement(shared_ptr<OperationExpression> conditionExprPtr, shared_ptr<StatementsList> stmtsListPtr)
        : conditionExpressionPtr(move(conditionExprPtr)), statementsListPtr(move(stmtsListPtr)) {}

	virtual void evaluate(Object&);
};

class ReturnStatement : public Statement {
    shared_ptr<OperationExpression> expressionPtr;

public:
    ReturnStatement(shared_ptr<OperationExpression> exprPtr)
        : expressionPtr(move(exprPtr)) {}
	
	ReturnStatement()
        : expressionPtr(nullptr) {}

	virtual void evaluate(Object&);
};

class FunctionDeclarationStatement : public Statement {
    shared_ptr<Function> functionPtr;
	shared_ptr<Identifier> identifierPtr;

public:
    FunctionDeclarationStatement(shared_ptr<Function> functPtr, shared_ptr<Identifier> idPtr)
        : functionPtr(move(functPtr)), identifierPtr(move(idPtr)) {}

	FunctionDeclarationStatement(shared_ptr<Function> functPtr)
		: functionPtr(move(functPtr)), identifierPtr(nullptr) {}

	virtual void evaluate(Object&);
	Function getFunction();
};

class ExpressionStatement : public Statement {
    shared_ptr<OperationExpression> operationExpressionPtr;

public:
	ExpressionStatement(shared_ptr<OperationExpression> opExprPtr)
        : operationExpressionPtr(move(opExprPtr)) {}

	virtual void evaluate(Object&);
};

class VariableDeclarationStatement : public Statement {
    shared_ptr<OperationExpressionsList> operationExpressionsListPtr;

public:
	VariableDeclarationStatement(shared_ptr<OperationExpressionsList> opExprListPtr)
        : operationExpressionsListPtr(move(opExprListPtr)) {}

	virtual void evaluate(Object&);
};

class LogStatement : public Statement {
	shared_ptr<IdentifierExpression> identifierExpressionPtr;

public:
	LogStatement(shared_ptr<IdentifierExpression> iePtr)
		: identifierExpressionPtr(move(iePtr)) {}

	virtual void evaluate(Object&);
};

#endif // STATEMENT_H_INCLUDED
