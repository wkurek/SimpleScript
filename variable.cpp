#include <stdexcept>
#include <iostream>

#include "variable.h"

ostream& operator<< (ostream& out, Variable variable) {
    if(variable.getType() == OBJECT) {
        return out << variable.getObject();
    } else if(variable.getType() == FUNCTION) {
        return out << variable.getFunction();
    } else {
        return out << variable.getPrimitive();
    }
}


VariableTypes Variable::getType() {
    return this->type;
}

Primitive Variable::getPrimitive() {
    return this->primitive;
}

Object Variable::getObject() {
    return this->object;
}

Function Variable::getFunction() {
    return this->funct;
}
