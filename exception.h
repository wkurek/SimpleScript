#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <memory>
using namespace std;

#include "variable.h"

class Variable;

class ParseException {
    const char* message;

public:
    ParseException(const char* msg) : message(msg) {}

    const char* what() const throw();
};

class ReturnVariable {
    shared_ptr<Variable> variablePtr;

public:
    ReturnVariable(shared_ptr<Variable> varPtr)
        : variablePtr(move(varPtr)) {}

    const char* what() const throw();
    Variable getVariable() const;

};

#endif // EXCEPTION_H_INCLUDED
