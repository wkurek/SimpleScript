#include "function.h"
#include "statement.h"
#include "variable.h"
#include "operation_expression.h"

ostream& operator<< (ostream& out, Function& fun) {
    return out << "function";
}

