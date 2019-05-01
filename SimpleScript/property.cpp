#include "property.h"
#include "variable.h"

bool Property::isOperationExpression() {
	return this->type == OPERATION_EXPRESSION_PROPERTY;
}

bool Property::isObjectLiteral() {
	return this->type == OBJECT_LITERAL_PROPERTY;
}

bool Property::isFunction() {
	return this->type == FUNCTION_PROPERTY;
}

string Property::getName() {
    return this->name;
}

Variable Property::evaluate(Object& scope) {
	if (this->isOperationExpression()) {
		return this->operationExpressionPtr->evaluate(scope);
	}
	else if (this->isObjectLiteral()) {
		return this->objectLiteralPtr->evaluate(scope);
	}
	else if (this->isFunction()) {
		return Variable(this->functionPtr);
	}
	else {
		return Variable();
	}
}

Variable PropertyList::evaluate(Object& scope) {
	Object object;

	for (std::list<shared_ptr<Property>>::iterator it = this->list.begin(); it != this->list.end(); ++it) {
		Identifier name((*it)->getName());
		Variable var = (*it)->evaluate(scope);

		if (var.isObject()) {
			object.getObject(name) = var.getObject();
		}
		else if (var.isFunction()) {
			object.getFunction(name) = var.getFunction();
		}
		else {
			object.getPrimitive(name) = var.getPrimitive();
		}
	}

	return Variable(shared_ptr<Object>(new Object(object)));
}


void PropertyList::add(shared_ptr<Property> property) {
    this->list.push_back(property);
}

Variable ObjectLiteral::evaluate(Object& scope) {
	return this->propertyListPtr->evaluate(scope);
}


