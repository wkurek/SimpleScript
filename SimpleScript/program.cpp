#include "object.h"
#include "statement.h"
#include "exception.h"
#include "statement.h"
#include "function.h"
#include "program.h"

#include <memory>
#include <string>
using namespace std;

#define PARAM_NAME "x"
#define LOG_FUNCTION_NAME "log"

Variable _PARSE_RESULT;

Function Program::generateLogFunction() {
	ParametersList* paramsListPtr = new ParametersList();

	string paramName = PARAM_NAME;
	paramsListPtr->add(paramName);

	Identifier* id = new Identifier(paramName);
	IdentifierExpression* ie =
		new IdentifierExpression(shared_ptr<Identifier>(id));

	LogStatement* stmt = new LogStatement(shared_ptr<IdentifierExpression>(ie));

	StatementsList* stmtsListPtr = new StatementsList();
	stmtsListPtr->add(shared_ptr<Statement>(stmt));

	Function funct = Function(shared_ptr<ParametersList>(paramsListPtr),
		shared_ptr<StatementsList>(stmtsListPtr));

	return funct;
}

void Program::generateEmbeddedConstructs(Object& scope) {
	string functionName = LOG_FUNCTION_NAME;
	Identifier functionId =  Identifier(functionName);
	scope.getFunction(functionId) = generateLogFunction();
}

void Program::evaluate() {
	Object globalScope = Object();

	try {
		this->generateEmbeddedConstructs(globalScope);
		this->statementsListPtr->evaluate(globalScope);
	}
	catch (ParseException parseException) {
		cerr << parseException.what() << endl;
	} 
	catch (ReturnVariable returnVariable) {
		_PARSE_RESULT = returnVariable.getVariable();
		cerr << "Program returned value:\t" << returnVariable.getVariable() << endl;
	}
}