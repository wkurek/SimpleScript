#ifndef PROPERTY_H_INCLUDED
#define PROPERTY_H_INCLUDED

#include "variable.h"

#include <iostream>
#include <string>
#include <list>
#include <memory>
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

class PropertyList {
    list<shared_ptr<Property>> list;

public:
    void add(shared_ptr<Property>);
	Object generateObject();
};

#endif // PROPERTY_H_INCLUDED
