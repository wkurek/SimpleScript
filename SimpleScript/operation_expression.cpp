#include <stdexcept>

#include "operation_expression.h"
#include "object.h"
#include "variable.h"

Variable ConstantExpression::evaluate(Object& scope) const {
    return *(this->variablePtr);
}

Variable IdentifierExpression::evaluate(Object& scope) const {
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
		return Variable();
    }
}

Variable FunctionCallExpression::evaluate(Object& scope) const {
	return this->functionPtr->call(scope, *(this->argumentsPtr));
}

Variable Negation::evaluate(Object& scope) const {
    return -(this->expressionPtr->evaluate(scope));
}

Variable LogicalNot::evaluate(Object& scope) const {
    return !(this->expressionPtr->evaluate(scope));
}

Variable Addition::evaluate(Object& scope) const {
    return (this->expression1Ptr->evaluate(scope)) + (this->expression2Ptr->evaluate(scope));
}

Variable Subtraction::evaluate(Object& scope) const {
    return (this->expression1Ptr->evaluate(scope)) - (this->expression2Ptr->evaluate(scope));
}

Variable Multiplication::evaluate(Object& scope) const {
    return (this->expression1Ptr->evaluate(scope)) * (this->expression2Ptr->evaluate(scope));
}

Variable Division::evaluate(Object& scope) const {
    return (this->expression1Ptr->evaluate(scope)) / (this->expression2Ptr->evaluate(scope));
}

Variable LessThan::evaluate(Object& scope) const {
    return Variable((this->expression1Ptr->evaluate(scope)) < (this->expression2Ptr->evaluate(scope)));
}

Variable GreaterThan::evaluate(Object& scope) const {
    return Variable((this->expression1Ptr->evaluate(scope)) > (this->expression2Ptr->evaluate(scope)));
}

Variable LessThanOrEqualTo::evaluate(Object& scope) const {
    return Variable((this->expression1Ptr->evaluate(scope)) <= (this->expression2Ptr->evaluate(scope)));
}

Variable GreaterThanOrEqualTo::evaluate(Object& scope)  const{
    return Variable((this->expression1Ptr->evaluate(scope)) >= (this->expression2Ptr->evaluate(scope)));
}

Variable Equals::evaluate(Object& scope)  const{
    return Variable((this->expression1Ptr->evaluate(scope)) == (this->expression2Ptr->evaluate(scope)));
}

Variable NotEquals::evaluate(Object& scope)  const{
    return Variable((this->expression1Ptr->evaluate(scope)) != (this->expression2Ptr->evaluate(scope)));
}

Variable LogicalOr::evaluate(Object& scope)  const{
    return Variable((this->expression1Ptr->evaluate(scope)) || (this->expression2Ptr->evaluate(scope)));
}

Variable LogicalAnd::evaluate(Object& scope)  const{
    return Variable((this->expression1Ptr->evaluate(scope)) && (this->expression2Ptr->evaluate(scope)));
}
