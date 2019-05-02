#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <memory>
using namespace std;

#include "variable.h"

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

class ZeroDivisionException : public ParseException {
public:
	ZeroDivisionException()
		: ParseException("Division by zero") {}
};

class UndefinedFunctionException : public ParseException {
public:
	UndefinedFunctionException(string functionName)
		: ParseException("Undefined function: " + functionName + "()") {}
};

class ParameterMismatchException : public ParseException {
public:
	ParameterMismatchException(unsigned int expected, unsigned int passed)
		: ParseException("Not enough parameters passed to function.") {}
};

class InvalidIdentifierException : public ParseException {
public:
	InvalidIdentifierException(string str)
		: ParseException("Invalid identifier: " + str) {}
};

#endif // EXCEPTION_H_INCLUDED
