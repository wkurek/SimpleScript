#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include "object.h"
#include "statement.h"
#include "exception.h"
#include "statement.h"
#include "function.h"

#include <memory>
using namespace std;

class Program {
	shared_ptr<StatementsList> statementsListPtr;

public:
	Program(shared_ptr<StatementsList> slPtr)
		: statementsListPtr(move(slPtr)) {}

	Function generateLogFunction();

	void generateEmbeddedConstructs(Object&);
	void evaluate();
};

#endif // PROGRAM_H_INCLUDED