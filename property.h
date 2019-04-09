#ifndef PROPERTY_H_INCLUDED
#define PROPERTY_H_INCLUDED

#include "variable.h"

#include <iostream>
#include <string>
using namespace std;

class Property {
    string name;
    Variable variable;

public:
    Property(string name, Variable variable):name(name), variable(variable) {}

    friend ostream& operator<< (ostream&, const Property);

    string getName();
    Variable getVariable();
};

#endif // PROPERTY_H_INCLUDED
