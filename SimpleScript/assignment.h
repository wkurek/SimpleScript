#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "property.h"

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

class ObjectLiteralAssignment : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
	shared_ptr<ObjectLiteral> objectLiteralPtr;

public:
	ObjectLiteralAssignment(shared_ptr<Identifier> idPtr, shared_ptr<ObjectLiteral> olPtr)
        : identifierPtr(move(idPtr)), objectLiteralPtr(move(olPtr)) {}

	Variable evaluate(Object&) const;
};

#endif // ASSIGNMENT_H_INCLUDED
