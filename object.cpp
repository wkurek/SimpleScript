#include <stdexcept>
#include <iostream>

#include "object.h"
#include "function.h"
#include "primitive.h"

ostream& operator<< (ostream& out, Object object) {

    out << "{ ";

    map<string, Primitive>::iterator it = object.primitives.begin();
    while(it != object.primitives.end()) {
        if(it != object.primitives.begin()) out << ", ";
        out << it->first << ": " << it->second;
        ++it;
    }

    map<string, Object>::iterator oit = object.objects.begin();
    while(oit != object.objects.end()) {
        if(oit != object.objects.begin()
           || !object.primitives.empty()) out << ", ";
        out << oit->first << ": " << oit->second;
        ++oit;
    }

    map<string, Function>::iterator fit = object.functions.begin();
    while(fit != object.functions.end()) {
        if(fit != object.functions.begin() || !object.primitives.empty()
           || !object.objects.empty()) out << ", ";
        out << fit->first << ": " << fit->second;
        ++fit;
    }

    return out << " }";
}

bool Object::hasObjectProperty(string propertyName) {
    map<string, Object>::iterator it =
            this->objects.find(propertyName);

    return it != this->objects.end();
}

Object& Object::getObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->objects[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
                .getObject(identifier.getTail());
}

Function& Object::getFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->functions[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
                .getFunction(identifier.getTail());
}

Primitive& Object::getPrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->primitives[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
            .getPrimitive(identifier.getTail());
}

void Object::removeObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        this->objects.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removeObject(identifier.getTail());
    }
}

void Object::removeFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        this->functions.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removeFunction(identifier.getTail());
    }
}

void Object::removePrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
            cout<<"remove"<<endl;
        this->primitives.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removePrimitive(identifier.getTail());
    }
}
