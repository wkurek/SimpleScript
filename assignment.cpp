#include "assignment.h"

OperationExpressionAssignment::~OperationExpressionAssignment() {
    delete this->expression;
}

void OperationExpressionAssignment::evaluate(Object scope) {
    Variable var = this->expression.evaluate(scope);

    if(var.getType() == PRIMITIVE) {
        scope.getPrimitive(this->identifier) = var.getPrimitive();
    } else if(var.getType() == OBJECT) {
        scope.getObject(this->identifier) = var.getObject();
    } else if(var.getType() == FUNCTION) {
        scope.getFunction(this->identifier) = var.getFunction();
    }
}

void FunctionAssignment::evaluate(Object scope) {
    scope.getFunction(this->identifier) = this->funct;
}

void ObjectAssignment::evaluate(Object scope) {
    scope.getObject(this->identifier) = this->object;
}
