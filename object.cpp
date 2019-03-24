#include <stdexcept>
#include <iostream>

#include "object.h"
#include "function.h"
#include "primitive.h"

bool Object::hasObjectProperty(Object object, string propertyName) {
    map<string, Object>::iterator it =
            object.objects.find(propertyName);

    return it != object.objects.end();
}

Object& Object::getObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->objects[identifier.getHead()];
    }

    if(!hasObjectProperty(*this, identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
                .getObject(identifier.getTail());
}

Function& Object::getFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->functions[identifier.getHead()];
    }

    if(!hasObjectProperty(*this, identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
                .getFunction(identifier.getTail());
}

Primitive& Object::getPrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->primitives[identifier.getHead()];
    }

    if(!hasObjectProperty(*this, identifier.getHead())) {
        throw invalid_argument("undefined");
    }

    return this->objects[identifier.getHead()]
            .getPrimitive(identifier.getTail());
}
