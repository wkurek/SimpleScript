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

    StatementsList trueStatementList;
    StatementsList falseStatementList;

public:
    ConditionalStatement(shared_ptr<OperationExpression> oePtr,
        StatementsList trueStmtList, StatementsList falseStmtList)
            : conditionExpressionPtr(move(oePtr)), trueStatementList(trueStmtList),
                falseStatementList(falseStmtList) {}

    ConditionalStatement(shared_ptr<OperationExpression> oePtr, StatementsList trueStmtList)
        : conditionExpressionPtr(move(oePtr)), trueStatementList(trueStmtList) {}

	virtual void evaluate(Object&);
};

class IterationStatement : public Statement {
    shared_ptr<OperationExpression> conditionExpressionPtr;
    StatementsList statementsList;

public:
    IterationStatement(shared_ptr<OperationExpression> conditionExprPtr, StatementsList stmtList)
        : conditionExpressionPtr(move(conditionExprPtr)), statementsList(stmtList) {}

	virtual void evaluate(Object&);
};

class ReturnStatement : public Statement {
    shared_ptr<OperationExpression> expressionPtr;

public:
    ReturnStatement(shared_ptr<OperationExpression> exprPtr)
        : expressionPtr(move(exprPtr)) {}

	virtual void evaluate(Object&);
};

class FunctionDeclarationStatement : public Statement {
    shared_ptr<Function> functionPtr;
    Identifier identifier;

public:
    FunctionDeclarationStatement(shared_ptr<Function> functPtr, Identifier id)
        : functionPtr(move(functPtr)), identifier(id) {}

	virtual void evaluate(Object&);
};

class ExpressionStatement : public Statement {
    shared_ptr<OperationExpression> operationExpressionPtr;

public:
	ExpressionStatement(shared_ptr<OperationExpression> opExprPtr)
        : operationExpressionPtr(move(opExprPtr)) {}

	virtual void evaluate(Object&);
};

#endif // STATEMENT_H_INCLUDED
