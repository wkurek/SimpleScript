#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"

class OperationExpressionAssignment : public OperationExpression {
    Identifier identifier;
    shared_ptr<OperationExpression> expressionPtr;

public:
    OperationExpressionAssignment(Identifier id, shared_ptr<OperationExpression> ePtr)
        : identifier(id), expressionPtr(move(ePtr)) {}

    Variable evaluate(Object&) const;
};

class FunctionAssignment : public OperationExpression {
    Identifier identifier;
    Function funct;

public:
    FunctionAssignment(Identifier id, Function f)
        : identifier(id), funct(f) {}

	Variable evaluate(Object&) const;
};

class ObjectAssignment : public OperationExpression {
    Identifier identifier;
    Object object;

public:
    ObjectAssignment(Identifier id, Object obj)
        : identifier(id), object(obj) {}

	Variable evaluate(Object&) const;
};

#endif // ASSIGNMENT_H_INCLUDED
