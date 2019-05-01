#include "object.h"
#include "statement.h"
#include "exception.h"
#include "program.h"

#include <memory>
using namespace std;

void Program::evaluate() {
	Object globalScope = Object();

	try {
		this->statementsListPtr->evaluate(globalScope);
	}
	catch (ParseException parseException) {
		cerr << parseException.what() << endl;
	}
}