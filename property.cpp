#include "property.h"

ostream& operator<< (ostream& out, const Property property) {
    return out << "{ " << property.name << ": " << property.variable << " }";
}

string Property::getName() {
    return this->name;
}

Variable Property::getVariable() {
    return this->variable;
}
