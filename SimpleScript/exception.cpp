#include <memory>
using namespace std;

#include "exception.h"
#include "variable.h"
#include "identifier.h"

const string ParseException::what() const throw() {
   return "[ERROR]\t" + this->message;
}

const string ReturnVariable::what() const throw() {
   return "ReturnVariable";
}

Variable ReturnVariable::getVariable() const {
    return *(this->variablePtr);
}
