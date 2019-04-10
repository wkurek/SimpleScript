#include <stdexcept>

#include "operation_expression.h"

UnaryOperationExpression::~UnaryOperationExpression() {
    delete this->expression;
}

BinaryOperationExpression::~BinaryOperationExpression() {
    delete this->expression1;
    delete this->expression2;
}

Variable ConstantExpression::evaluate(Object scope) {
    return this->variable;
}

Variable IdentifierExpression::evaluate(Object scope) {
    if(scope.hasObject(this->identifier)) {
        return scope.getObject(this->identifier);
    } else if(scope.hasFunction(this->identifier)) {
        return scope.getFunction(this->identifier);
    } else if(scope.hasPrimitive(this->identifier)) {
        return scope.getPrimitive(this->identifier);
    } else {
        throw invalid_argument("undefined");
    }
}

Variable Negation::evaluate(Object scope) {
    return -(this->expression->evaluate(scope));
}

Variable LogicalNot::evaluate(Object scope) {
    return !(this->expression->evaluate(scope));
}
