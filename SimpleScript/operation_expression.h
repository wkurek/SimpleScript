#ifndef OPERATION_EXPRESSION_H_INCLUDED
#define OPERATION_EXPRESSION_H_INCLUDED

#include <iostream>
#include <memory>
using namespace std;

#include "object.h"
#include "variable.h"
#include "function.h"

class Object;
class Variable;
class Function;
class ArgumentsList;

class OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
};

class OperationExpressionsList {
	list<shared_ptr<OperationExpression>> operationExpressionsList;

public:
	void add(shared_ptr<OperationExpression>);
	list<shared_ptr<OperationExpression>>::iterator begin();
	list<shared_ptr<OperationExpression>>::iterator end();

	size_t size() const;

	void evaluate(Object&);
};

class UnaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
    UnaryOperationExpression(shared_ptr<OperationExpression> ePtr)
        : expressionPtr(move(ePtr)) {}

protected:
    shared_ptr<OperationExpression> expressionPtr;
};

class BinaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
    BinaryOperationExpression(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : expression1Ptr(move(e1Ptr)), expression2Ptr(move(e2Ptr)) {}

protected:
    shared_ptr<OperationExpression> expression1Ptr;
    shared_ptr<OperationExpression> expression2Ptr;
};

class ConstantExpression : public OperationExpression {
    shared_ptr<Variable> variablePtr;

public:
    ConstantExpression(shared_ptr<Variable> varPtr): variablePtr(move(varPtr)) {}
    virtual Variable evaluate(Object&) const;
};

class IdentifierExpression : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;

public:
    IdentifierExpression(shared_ptr<Identifier> idPtr) 
		: identifierPtr(move(idPtr)) {}

    virtual Variable evaluate(Object&) const;
};

class FunctionCallExpression : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
	shared_ptr<ArgumentsList> argumentsPtr;

public:
	FunctionCallExpression(shared_ptr<Identifier> idPtr,
		shared_ptr<ArgumentsList> args)
		: identifierPtr(move(idPtr)), argumentsPtr(move(args)) {}

	virtual Variable evaluate(Object&) const;
};

class Negation : public UnaryOperationExpression {
public:
    Negation(shared_ptr<OperationExpression> ePtr)
        : UnaryOperationExpression(move(ePtr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalNot : public UnaryOperationExpression {
public:
    LogicalNot(shared_ptr<OperationExpression> ePtr)
        : UnaryOperationExpression(move(ePtr)) {}
    virtual Variable evaluate(Object&) const;
};

class Addition : public BinaryOperationExpression {
public:
    Addition(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Subtraction : public BinaryOperationExpression {
public:
    Subtraction (shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Multiplication : public BinaryOperationExpression {
public:
    Multiplication(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Division : public BinaryOperationExpression {
public:
    Division(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LessThan : public BinaryOperationExpression {
public:
    LessThan(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class GreaterThan : public BinaryOperationExpression {
public:
    GreaterThan(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LessThanOrEqualTo : public BinaryOperationExpression {
public:
    LessThanOrEqualTo(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class GreaterThanOrEqualTo : public BinaryOperationExpression {
public:
    GreaterThanOrEqualTo(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Equals : public BinaryOperationExpression {
public:
    Equals(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class NotEquals : public BinaryOperationExpression {
public:
    NotEquals(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalOr : public BinaryOperationExpression {
public:
    LogicalOr(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalAnd : public BinaryOperationExpression {
public:
    LogicalAnd(shared_ptr<OperationExpression> e1Ptr, shared_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};



#endif // OPERATION_EXPRESSION_H_INCLUDED
