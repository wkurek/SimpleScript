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

void PropertyList::add(Property property) {
    this->list.push_back(property);
}

Object PropertyList::generateObject() {
    Object object;

    for (auto it = this->list.begin(); it != this->list.end(); ++it){
        Identifier name(it->getName());

        if(it->getVariable().getType() == OBJECT) {
            object.getObject(name) = it->getVariable().getObject();
        } else if(it->getVariable().getType() == FUNCTION) {
            object.getFunction(name) = it->getVariable().getFunction();
        } else {
            object.getPrimitive(name) = it->getVariable().getPrimitive();
        }
    }

    return object;
}
