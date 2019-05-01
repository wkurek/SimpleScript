#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"

class OperationExpressionAssignment : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
    shared_ptr<OperationExpression> expressionPtr;

public:
    OperationExpressionAssignment(shared_ptr<Identifier> idPtr, shared_ptr<OperationExpression> ePtr)
        : identifierPtr(move(idPtr)), expressionPtr(move(ePtr)) {}

    Variable evaluate(Object&) const;
};

class FunctionAssignment : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
    Function funct;

public:
    FunctionAssignment(shared_ptr<Identifier> idPtr, Function f)
        : identifierPtr(move(idPtr)), funct(f) {}

	Variable evaluate(Object&) const;
};

class ObjectAssignment : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
    Object object;

public:
    ObjectAssignment(shared_ptr<Identifier> idPtr, Object obj)
        : identifierPtr(move(idPtr)), object(obj) {}

	Variable evaluate(Object&) const;
};

#endif // ASSIGNMENT_H_INCLUDED
