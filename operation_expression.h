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
    ConstantExpression(Variable var): variable(var) {}
    virtual Variable evaluate(Object) const;
};

class IdentifierExpression : public OperationExpression {
    Identifier identifier;

public:
    IdentifierExpression(Identifier id) : identifier(id) {}
    virtual Variable evaluate(Object) const;
};

class Negation : public UnaryOperationExpression {
public:
    Negation(OperationExpression* exp) : UnaryOperationExpression(exp) {}
    virtual Variable evaluate(Object) const;
};

class LogicalNot : public UnaryOperationExpression {
public:
    LogicalNot(OperationExpression* exp) : UnaryOperationExpression(exp) {}
    virtual Variable evaluate(Object) const;
};



#endif // OPERATION_EXPRESSION_H_INCLUDED
