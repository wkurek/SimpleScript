#include <memory>
using namespace std;

#include "exception.h"
#include "variable.h"

const char* ParseException::what() const throw() {
   return this->message;
}

const char* ReturnVariable::what() const throw() {
   return "ReturnVariable";
}

Variable ReturnVariable::getVariable() const {
    return *(this->variablePtr);
}
