#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"
#include "operation_expression.h"

class Object;
class OperationExpression;

class Statement {
public:
    virtual void evaluate(Object) const = 0;
};

class StatementsList {
    list<shared_ptr<Statement>> statements;

public:
    void evaluate(Object);

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

    void evaluate(Object);
};

class IterationStatement {
    shared_ptr<OperationExpression> conditionExpressionPtr;
    StatementsList statementsList;

public:
    IterationStatement(shared_ptr<OperationExpression> conditionExprPtr, StatementsList stmtList)
        : conditionExpressionPtr(move(conditionExprPtr)), statementsList(stmtList) {}

    void evaluate(Object);
};


#endif // STATEMENT_H_INCLUDED
