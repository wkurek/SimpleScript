#include <stdexcept>
#include <iostream>

#include "variable.h"

bool Variable::isPrimitive() const {
    return this->type == PRIMITIVE;
}

bool Variable::isObject() const {
    return this->type == OBJECT;
}

bool Variable::isFunction() const {
    return this->type == FUNCTION;
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

ostream& operator<< (ostream& out, Variable variable) {
    if(variable.isObject()) return out << variable.object;
    if(variable.isFunction()) return out << variable.funct;
    else return out << variable.primitive;
}

bool operator== (const Variable& var1, const Variable& var2) {
    if(var1.isObject() && var2.isObject()) return var1.object == var2.object;
    else if(var1.isFunction() && var2.isFunction()) return var1.funct == var2.funct;
    else if(var1.isPrimitive() && var2.isPrimitive()) return var1.primitive == var2.primitive;
    else return false;
}

bool operator!= (const Variable& var1, const Variable& var2) {
    return !(var1 == var2);
}

bool operator< (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return var1.primitive < var2.primitive;
    else return false;
}

bool operator> (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return var1.primitive > var2.primitive;
    else return false;
}

bool operator<= (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return var1.primitive <= var2.primitive;
    else return false;
}

bool operator>= (const Variable& var1, const Variable& var2) {
    if(var1.isPrimitive() && var2.isPrimitive()) return var1.primitive >= var2.primitive;
    else return false;
}


Variable::operator bool() const {
    if(this->isPrimitive()) return this->primitive.operator bool();
    else return true;
}

Variable& Variable::operator=(const Variable& var) {
    this->type = var.type;

    if(this->isObject()) this->object = var.object;
    else if (this->isFunction()) this->funct = var.funct;
    else if (this->isPrimitive()) this->primitive = var.primitive;

    return *this;
}

Variable  Variable::operator+(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) return Variable(this->primitive + var.primitive);
    else return *this;
}

Variable  Variable::operator-(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) return Variable(this->primitive - var.primitive);
    else return *this;
}

Variable  Variable::operator*(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) return Variable(this->primitive * var.primitive);
    else return *this;
}

Variable  Variable::operator/(const Variable& var) const {
    if(this->isPrimitive() && var.isPrimitive()) return Variable(this->primitive / var.primitive);
    else return *this;
}

Variable  Variable::operator-() const {
    if(this->isPrimitive()) return Variable(-this->primitive);
    else return *this;
}

Variable  Variable::operator++() const {
    if(this->isPrimitive()) return Variable(++this->primitive);
    else return *this;
}

Variable  Variable::operator--() const {
    if(this->isPrimitive()) return Variable(--this->primitive);
    else return *this;
}

Variable  Variable::operator!() const {
    if(this->isPrimitive()) return Variable(!this->primitive);
    else return *this;
}

