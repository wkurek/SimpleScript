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
    Primitive(const Primitive &p) 
		: type(p.type), intVal(p.intVal), floatVal(p.floatVal), 
		boolVal(p.boolVal), stringVal(p.stringVal) {}

    Primitive() : type(INTEGER), intVal(0), floatVal(0.0), 
		boolVal(false), stringVal("") {}

	explicit Primitive(const int i) : type(INTEGER), intVal(i), floatVal(0.0),
		boolVal(false), stringVal("") {}

    Primitive(const float f)  :type(FLOAT), intVal(0), floatVal(f),
		boolVal(false), stringVal("") {}

    Primitive(const bool b) : type(BOOLEAN), intVal(0), floatVal(0.0), 
		boolVal(b), stringVal("") {}

	explicit Primitive(const string str) 
		: type(STRING), intVal(0), floatVal(0.0),
		boolVal(false), stringVal(str) {}

	explicit Primitive(const string str, bool quotation) {
		this->type = STRING;

		if (quotation) {
			this->stringVal = 
				str.substr(1, str.length() - 2);
		}
		else {
			this->stringVal = str;
		}

		this->intVal = 0;
		this->floatVal = 0.0f;
		this->boolVal = false;
	}

	bool isInteger();
	bool isFloat();
	bool isBoolean();
	bool isString();

	int getInteger();
	float getFloat();
	bool getBoolean();
	string getString();

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
