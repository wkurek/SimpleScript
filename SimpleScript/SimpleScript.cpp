#include <iostream>

#include "identifier.h"
#include "object.h"
#include "primitive.h"
#include "function.h"
#include "variable.h"
#include "property.h"
#include "operation_expression.h"
#include "assignment.h"

using namespace std;

int main()
{
	Object globalScope = Object();

	Identifier aIdentifier = Identifier("a");
	Variable aVariable = Variable(4);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(new Identifier(aIdentifier)),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable result = aExpressionAssignment.evaluate(globalScope);

	cout << globalScope << endl;

	Statement* stmt = new FunctionDeclarationStatement(std::shared_ptr<Function>(new Function()));

	FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> (stmt);
	fdstmtPtr->getFunction();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
