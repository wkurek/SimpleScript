#include "object.h"
#include "statement.h"
#include "exception.h"
#include "statement.h"
#include "function.h"
#include "program.h"

#include <memory>
#include <string>
using namespace std;

void Program::generateEmbeddedConstructs(Object& scope) {
	ParametersList* paramsListPtr = new ParametersList();

	string paramName = "x";
	paramsListPtr->add(paramName);

	Identifier* id = new Identifier(paramName);
	IdentifierExpression* ie = 
		new IdentifierExpression(shared_ptr<Identifier>(id));

	LogStatement* stmt = new LogStatement(shared_ptr<IdentifierExpression>(ie));

	StatementsList* stmtsListPtr = new StatementsList();
	stmtsListPtr->add(shared_ptr<Statement>(stmt));

	Function funct = Function(shared_ptr<ParametersList>(paramsListPtr), 
		shared_ptr<StatementsList>(stmtsListPtr));

	string functionName = "log";
	Identifier functionId =  Identifier(functionName);
	scope.getFunction(functionId) = funct;
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
		cerr << "Program returned value" << returnVariable.getVariable() << endl;
	}
}