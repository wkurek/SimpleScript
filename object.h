#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <map>
#include <string>

#include "function.h"
#include "identifier.h"
#include "primitive.h"

using namespace std;

class Object {
    map<string, Object> objects;
    map<string, Function> functions;
    map<string, Primitive> primitives;

    bool hasObjectProperty(string);

public:

    friend ostream& operator<< (ostream&, Object&);

    Object& getObject(Identifier);
    Function& getFunction(Identifier);
    Primitive& getPrimitive(Identifier);

    void removeObject(Identifier);
    void removeFunction(Identifier);
    void removePrimitive(Identifier);
};

#endif // OBJECT_H_INCLUDED
