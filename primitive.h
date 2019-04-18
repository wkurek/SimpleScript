#ifndef PRIMITIVE_H_INCLUDED
#define PRIMITIVE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef enum PrimitiveTypes { INTEGER, FLOAT, BOOLEAN, STRING } PrimitiveTypes;

class Primitive {
    PrimitiveTypes type;

    int intVal;
    float floatVal;
    bool boolVal;
    string stringVal;

public:
    Primitive(const Primitive &p):type(p.type), intVal(p.intVal), floatVal(p.floatVal), boolVal(p.boolVal), stringVal(p.stringVal) {}
    Primitive():type(INTEGER), intVal(0) {}
    Primitive(const int i):type(INTEGER), intVal(i) {}
    Primitive(const float f):type(FLOAT), floatVal(f) {}
    Primitive(const bool b):type(BOOLEAN), boolVal(b) {}
    Primitive(const string str):type(STRING), stringVal(str) {}

    friend ostream& operator<< (ostream&, const Primitive&);
    friend bool     operator== (const Primitive&, const Primitive&);
    friend bool     operator!= (const Primitive&, const Primitive&);
    friend bool     operator<  (const Primitive&, const Primitive&);
    friend bool     operator>  (const Primitive&, const Primitive&);
    friend bool     operator<= (const Primitive&, const Primitive&);
    friend bool     operator>= (const Primitive&, const Primitive&);

    operator bool() const;

    Primitive& operator=  (const Primitive&);

    Primitive  operator+  (const Primitive&) const;
    Primitive  operator-  (const Primitive&) const;
    Primitive  operator*  (const Primitive&) const;
    Primitive  operator/  (const Primitive&) const;
    Primitive  operator-  () const;
    Primitive  operator++ () const;
    Primitive  operator-- () const;
    Primitive  operator! () const;

};

#endif // PRIMITIVE_H_INCLUDED
