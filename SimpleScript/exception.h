#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <memory>
using namespace std;

#include "variable.h"
#include "identifier.h"

class Variable;

class ParseException {
	string message;

public:
    ParseException(string msg) : message(msg) {}

	const string what() const throw();
};

class ReturnVariable {
    shared_ptr<Variable> variablePtr;

public:
    ReturnVariable(shared_ptr<Variable> varPtr)
        : variablePtr(move(varPtr)) {}

    const string what() const throw();
    Variable getVariable() const;

};

class UndefinedFunctionException : public ParseException {
public:
	UndefinedFunctionException(Identifier id)
		: ParseException("Undefined function:\t" + id.operator std::string()) {}
};

#endif // EXCEPTION_H_INCLUDED
