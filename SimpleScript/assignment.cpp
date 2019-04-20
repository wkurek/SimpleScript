#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "assignment.h"

Variable OperationExpressionAssignment::evaluate(Object scope) const {
    Variable var = this->expressionPtr->evaluate(scope);

    if(var.isPrimitive()) {
        scope.getPrimitive(this->identifier) = var.getPrimitive();

        scope.removeObject(this->identifier);
        scope.removeFunction(this->identifier);
    } else if(var.isObject()) {
        scope.getObject(this->identifier) = var.getObject();

        scope.removePrimitive(this->identifier);
        scope.removeFunction(this->identifier);
    } else if(var.isFunction()) {
        scope.getFunction(this->identifier) = var.getFunction();

        scope.removePrimitive(this->identifier);
        scope.removeObject(this->identifier);
    }

	return var;
}

Variable FunctionAssignment::evaluate(Object scope) const {
    scope.getFunction(this->identifier) = this->funct;

	return Variable(shared_ptr<Function>(new Function(this->funct)));
}

Variable ObjectAssignment::evaluate(Object scope) const {
    scope.getObject(this->identifier) = this->object;

	return Variable(shared_ptr<Object>(new Object(this->object)));
}
