#include "assignment.h"

OperationExpressionAssignment::~OperationExpressionAssignment() {
    delete this->expression;
}

void OperationExpressionAssignment::evaluate(Object scope) const {
    Variable var = this->expression->evaluate(scope);

    if(var.getType() == PRIMITIVE) {
        scope.getPrimitive(this->identifier) = var.getPrimitive();

        scope.removeObject(this->identifier);
        scope.removeFunction(this->identifier);
    } else if(var.getType() == OBJECT) {
        scope.getObject(this->identifier) = var.getObject();

        scope.removePrimitive(this->identifier);
        scope.removeFunction(this->identifier);
    } else if(var.getType() == FUNCTION) {
        scope.getFunction(this->identifier) = var.getFunction();

        scope.removePrimitive(this->identifier);
        scope.removeObject(this->identifier);
    }
}

void FunctionAssignment::evaluate(Object scope) const {
    scope.getFunction(this->identifier) = this->funct;
}

void ObjectAssignment::evaluate(Object scope) const {
    scope.getObject(this->identifier) = this->object;
}
