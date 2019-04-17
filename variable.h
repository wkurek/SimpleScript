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

    friend ostream& operator<< (ostream&, Variable&);
    friend bool     operator== (const Variable&, const Variable&);
    friend bool     operator!= (const Variable&, const Variable&);
    friend bool     operator<  (const Variable&, const Variable&);
    friend bool     operator>  (const Variable&, const Variable&);
    friend bool     operator<= (const Variable&, const Variable&);
    friend bool     operator>= (const Variable&, const Variable&);

    operator bool() const;

    Variable& operator=  (const Variable&);

    Variable  operator+  (const Variable&) const;
    Variable  operator-  (const Variable&) const;
    Variable  operator*  (const Variable&) const;
    Variable  operator/  (const Variable&) const;
    Variable  operator-  () const;
    Variable  operator++ () const;
    Variable  operator-- () const;
    Variable  operator! () const;

    bool isPrimitive() const;
    bool isObject()const;
    bool isFunction()const;

    VariableTypes getType();
    Primitive getPrimitive();
    Object getObject();
    Function getFunction();
};


#endif // VALUE_H_INCLUDED
