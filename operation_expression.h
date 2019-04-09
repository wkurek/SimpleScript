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
    ~UnaryOperationExpression();

protected:
    OperationExpression* expression;
};

class BinaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object) const = 0;
    BinaryOperationExpression(OperationExpression* exp1, OperationExpression* exp2) : expression1(exp1), expression2(exp2) {}
    ~BinaryOperationExpression();

protected:
    OperationExpression* expression1;
    OperationExpression* expression2;
};

class ConstantExpression : public OperationExpression {
    Variable variable;

public:
    virtual Variable evaluate(Object) const;
    ConstantExpression(Variable var): variable(var) {}
};

class IdentifierExpression : public OperationExpression {
    Identifier identifier;

public:
    virtual Variable evaluate(Object) const;
    IdentifierExpression(Identifier id) : identifier(id) {}
};

#endif // OPERATION_EXPRESSION_H_INCLUDED
