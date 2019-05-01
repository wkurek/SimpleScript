#ifndef PROPERTY_H_INCLUDED
#define PROPERTY_H_INCLUDED

#include "variable.h"
#include "operation_expression.h"
#include "function.h"

#include <iostream>
#include <string>
#include <list>
#include <memory>
using namespace std;


typedef enum PropertyTypes { OPERATION_EXPRESSION_PROPERTY, OBJECT_LITERAL_PROPERTY, FUNCTION_PROPERTY } PropertyTypes;

class ObjectLiteral;

class Property {
    string name;

	PropertyTypes type;
	shared_ptr<OperationExpression> operationExpressionPtr;
	shared_ptr<ObjectLiteral> objectLiteralPtr;
	shared_ptr<Function> functionPtr;

public:
    Property(string name, shared_ptr<OperationExpression> oePtr)
		:name(name), operationExpressionPtr(move(oePtr)), 
		type(OPERATION_EXPRESSION_PROPERTY) {}
	
	Property(string name, shared_ptr<ObjectLiteral> olPtr)
		:name(name), objectLiteralPtr(move(olPtr)), 
		type(OBJECT_LITERAL_PROPERTY) {}

	Property(string name, shared_ptr<Function> fPtr)
		:name(name), functionPtr(move(fPtr)), 
		type(FUNCTION_PROPERTY) {}

	bool isOperationExpression();
	bool isObjectLiteral();
	bool isFunction();

	string getName();

	Variable evaluate(Object&);

};

class PropertyList {
    list<shared_ptr<Property>> list;

public:
    void add(shared_ptr<Property>);
	Variable evaluate(Object&);
};

class ObjectLiteral {
	shared_ptr<PropertyList> propertyListPtr;

public:
	ObjectLiteral(shared_ptr<PropertyList> plPtr)
		:propertyListPtr(move(plPtr)) {}

	Variable evaluate(Object&);
};

#endif // PROPERTY_H_INCLUDED
