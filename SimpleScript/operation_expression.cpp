#include <stdexcept>

#include "operation_expression.h"
#include "object.h"
#include "variable.h"
#include "exception.h"

Variable ConstantExpression::evaluate(Object& scope) const {
    return *(this->variablePtr);
}

Variable IdentifierExpression::evaluate(Object& scope) const {
    if(scope.hasObject(*(this->identifierPtr))) {
        Object *obj = new Object();
        *obj = scope.getObject(*(this->identifierPtr));
        return Variable(shared_ptr<Object>(obj));
    } else if(scope.hasFunction(*(this->identifierPtr))) {
        Function *func = new Function();
        *func = scope.getFunction(*(this->identifierPtr));
        return Variable(shared_ptr<Function>(func));
    } else if(scope.hasPrimitive(*(this->identifierPtr))) {
        return scope.getPrimitive(*(this->identifierPtr));
    } else {
		return Variable();
    }
}

Variable FunctionCallExpression::evaluate(Object& scope) const {
	if (!scope.hasFunction(*(this->identifierPtr))) {
		throw UndefinedFunctionException(
			this->identifierPtr->operator std::string());
	}

	Function function = scope.getFunction(*(this->identifierPtr));

	return function.call(scope, *(this->argumentsPtr));
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
	if (this->expression2Ptr->evaluate(scope) == 0) {
		throw ZeroDivisionException();
	}

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

void OperationExpressionsList::add(shared_ptr<OperationExpression> oex) {
	this->operationExpressionsList.push_back(oex);
}

list<shared_ptr<OperationExpression>>::iterator OperationExpressionsList::begin() {
	return this->operationExpressionsList.begin();
}

list<shared_ptr<OperationExpression>>::iterator OperationExpressionsList::end() {
	return this->operationExpressionsList.end();
}

size_t OperationExpressionsList::size() const {
	return this->operationExpressionsList.size();
}

void OperationExpressionsList::evaluate(Object& scope) {
	for (auto it = this->begin(); it != this->end(); ++it) {
		(*it)->evaluate(scope);
	}
}