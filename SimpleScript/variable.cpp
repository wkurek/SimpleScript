#include <iostream>
#include <memory>
using namespace std;

#include "variable.h"
#include "identifier.h"
#include "primitive.h"
#include "object.h"
#include "function.h"

bool Variable::isPrimitive() const {
    return this->type == PRIMITIVE;
}

bool Variable::isObject() const {
    return this->type == OBJECT;
}

bool Variable::isFunction() const {
    return this->type == FUNCTION;
}

Primitive Variable::getPrimitive() {
    return *(this->primitivePtr);
}

Object Variable::getObject() {
    return *(this->objectPtr);
}

Function Variable::getFunction() {
    return *(this->functionPtr);
}

ostream& operator<< (ostream& out, Variable variable) {
    if(variable.isObject()) return out << *(variable.objectPtr);
    if(variable.isFunction()) return out << *(variable.functionPtr);
    else return out << *(variable.primitivePtr);
}

bool operator== (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return *(var1.primitivePtr) == *(var2.primitivePtr);
    else return false;
}

bool operator!= (const Variable& var1, const Variable& var2) {
    return !(var1 == var2);
}

bool operator< (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return *(var1.primitivePtr) < *(var2.primitivePtr);
    else return false;
}

bool operator> (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return *(var1.primitivePtr) > *(var2.primitivePtr);
    else return false;
}

bool operator<= (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return *(var1.primitivePtr) <= *(var2.primitivePtr);
    else return false;
}

bool operator>= (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return *(var1.primitivePtr) >= *(var2.primitivePtr);
    else return false;
}


Variable::operator bool() const {
    if(this->isPrimitive()) return (*this->primitivePtr).operator bool();
    else return true;
}

Variable& Variable::operator=(const Variable& var) {
    this->type = var.type;

    if(this->isObject()) this->objectPtr = var.objectPtr;
    else if (this->isFunction()) this->functionPtr = var.functionPtr;
    else if (this->isPrimitive()) this->primitivePtr = var.primitivePtr;

    return *this;
}

Variable Variable::operator+(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) {
        Primitive result = *this->primitivePtr + *var.primitivePtr;
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator-(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) {
        Primitive result = *this->primitivePtr - *var.primitivePtr;
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator*(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) {
        Primitive result = *this->primitivePtr * *var.primitivePtr;
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator/(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) {
        Primitive result = *this->primitivePtr / *var.primitivePtr;
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator-() const {
    if(this->isPrimitive()) {
        Primitive result = -(*this->primitivePtr);
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator++() const {
    if(this->isPrimitive()) {
        Primitive result = ++(*this->primitivePtr);
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator--() const {
    if(this->isPrimitive()) {
        Primitive result = --(*this->primitivePtr);
        return Variable(result);
    }
    else return *this;
}

Variable Variable::operator!() const {
    if(this->isPrimitive()) {
        Primitive result = !(*this->primitivePtr);
        return Variable(result);
    }
    else return *this;
}

