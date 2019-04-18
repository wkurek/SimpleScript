#include <stdexcept>

#include "operation_expression.h"
#include "object.h"
#include "variable.h"

UnaryOperationExpression::~UnaryOperationExpression() {
    delete this->expression;
}

BinaryOperationExpression::~BinaryOperationExpression() {
    delete this->expression1;
    delete this->expression2;
}

Variable ConstantExpression::evaluate(Object scope) const {
    return *(this->variablePtr);
}

Variable IdentifierExpression::evaluate(Object scope) const {
    if(scope.hasObject(this->identifier)) {
        Object *obj = new Object();
        *obj = scope.getObject(this->identifier);
        return Variable(shared_ptr<Object>(obj));
    } else if(scope.hasFunction(this->identifier)) {
        Function *func = new Function();
        *func = scope.getFunction(this->identifier);
        return Variable(shared_ptr<Function>(func));
    } else if(scope.hasPrimitive(this->identifier)) {
        return scope.getPrimitive(this->identifier);
    } else {
        throw invalid_argument("undefined");
    }
}

Variable Negation::evaluate(Object scope) const {
    return -(this->expression->evaluate(scope));
}

Variable LogicalNot::evaluate(Object scope) const {
    return !(this->expression->evaluate(scope));
}

Variable Addition::evaluate(Object scope) const {
    return (this->expression1->evaluate(scope)) + (this->expression2->evaluate(scope));
}

Variable Subtraction::evaluate(Object scope) const {
    return (this->expression1->evaluate(scope)) - (this->expression2->evaluate(scope));
}

Variable Multiplication::evaluate(Object scope) const {
    return (this->expression1->evaluate(scope)) * (this->expression2->evaluate(scope));
}

Variable Division::evaluate(Object scope) const {
    return (this->expression1->evaluate(scope)) / (this->expression2->evaluate(scope));
}

Variable LessThan::evaluate(Object scope) const {
    return Variable((this->expression1->evaluate(scope)) < (this->expression2->evaluate(scope)));
}

Variable GreaterThan::evaluate(Object scope) const {
    return Variable((this->expression1->evaluate(scope)) > (this->expression2->evaluate(scope)));
}

Variable LessThanOrEqualTo::evaluate(Object scope) const {
    return Variable((this->expression1->evaluate(scope)) <= (this->expression2->evaluate(scope)));
}

Variable GreaterThanOrEqualTo::evaluate(Object scope)  const{
    return Variable((this->expression1->evaluate(scope)) >= (this->expression2->evaluate(scope)));
}

Variable Equals::evaluate(Object scope)  const{
    return Variable((this->expression1->evaluate(scope)) == (this->expression2->evaluate(scope)));
}

Variable NotEquals::evaluate(Object scope)  const{
    return Variable((this->expression1->evaluate(scope)) != (this->expression2->evaluate(scope)));
}

Variable LogicalOr::evaluate(Object scope)  const{
    return Variable((this->expression1->evaluate(scope)) || (this->expression2->evaluate(scope)));
}

Variable LogicalAnd::evaluate(Object scope)  const{
    return Variable((this->expression1->evaluate(scope)) && (this->expression2->evaluate(scope)));
}
