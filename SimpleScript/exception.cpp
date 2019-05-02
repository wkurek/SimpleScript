#include <memory>
using namespace std;

#include "exception.h"
#include "variable.h"

const string ParseException::what() const throw() {
   return this->message;
}

const string ReturnVariable::what() const throw() {
   return "ReturnVariable";
}

Variable ReturnVariable::getVariable() const {
    return *(this->variablePtr);
}
