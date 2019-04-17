#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "statement.h"

class OperationExpressionAssignment : public Statement {
    Identifier identifier;
    OperationExpression* expression;

public:
    OperationExpressionAssignment(Identifier id, OperationExpression* ex) : identifier(id), expression(ex) {}
    ~OperationExpressionAssignment();

    void evaluate(Object) const;
};

class FunctionAssignment {
    Identifier identifier;
    Function funct;

public:
    FunctionAssignment(Identifier id, Function f) : identifier(id), funct(f) {}

    void evaluate(Object) const;
};

class ObjectAssignment {
    Identifier identifier;
    Object object;

public:
    ObjectAssignment(Identifier id, Object obj) : identifier(id), object(obj) {}

    void evaluate(Object) const;
};

#endif // ASSIGNMENT_H_INCLUDED
