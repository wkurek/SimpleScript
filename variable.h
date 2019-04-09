#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

#include "function.h"
#include "identifier.h"
#include "object.h"

#include <iostream>
using namespace std;

typedef enum VariableTypes { PRIMITIVE, OBJECT, FUNCTION } ValueTypes;

class Variable {
    VariableTypes type;
    Primitive primitive;
    Object object;
    Function funct;

    friend ostream& operator<< (ostream&, Variable);

public:
    Variable():type(PRIMITIVE), primitive() {}
    Variable(Primitive primitive):type(PRIMITIVE), primitive(primitive) {}
    Variable(Object object):type(OBJECT), object(object) {}
    Variable(Function funct):type(FUNCTION), funct(funct) {}

    VariableTypes getType();
    Primitive getPrimitive();
    Object getObject();
    Function getFunction();
};


#endif // VALUE_H_INCLUDED
