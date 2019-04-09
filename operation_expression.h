#ifndef OPERATION_EXPRESSION_H_INCLUDED
#define OPERATION_EXPRESSION_H_INCLUDED

#include "variable.h"
#include "object.h"

class OperationExpression {
public:
    virtual Variable evaluate(Object) const = 0;
};

class UnaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object) const = 0;
    UnaryOperationExpression(OperationExpression* exp) : expression(exp) {}

protected:
    OperationExpression* expression;
};

class BinaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object) const = 0;
    BinaryOperationExpression(OperationExpression* exp1, OperationExpression* exp2) : expression1(exp1), expression2(exp2) {}

protected:
    OperationExpression* expression1;
    OperationExpression* expression2;
};

#endif // OPERATION_EXPRESSION_H_INCLUDED
