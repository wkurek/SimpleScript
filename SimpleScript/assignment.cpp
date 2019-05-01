#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "assignment.h"
#include "property.h"

Variable OperationExpressionAssignment::evaluate(Object& scope) const {
    Variable var = this->expressionPtr->evaluate(scope);

    if(var.isPrimitive()) {
        scope.getPrimitive(*(this->identifierPtr)) = var.getPrimitive();

        scope.removeObject(*(this->identifierPtr));
        scope.removeFunction(*(this->identifierPtr));
    } else if(var.isObject()) {
        scope.getObject(*(this->identifierPtr)) = var.getObject();

        scope.removePrimitive(*(this->identifierPtr));
        scope.removeFunction(*(this->identifierPtr));
    } else if(var.isFunction()) {
        scope.getFunction(*(this->identifierPtr)) = var.getFunction();

        scope.removePrimitive(*(this->identifierPtr));
        scope.removeObject(*(this->identifierPtr));
    }

	return var;
}

Variable FunctionAssignment::evaluate(Object& scope) const {
    scope.getFunction(*(this->identifierPtr)) = this->funct;

	return Variable(shared_ptr<Function>(new Function(this->funct)));
}

Variable ObjectLiteralAssignment::evaluate(Object& scope) const {
	Variable var = this->objectLiteralPtr->evaluate(scope);

	scope.getObject(*(this->identifierPtr)) = var.getObject();

	return var;
}
