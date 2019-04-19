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
	Identifier identifier("parentName");
	Identifier identifirChild(identifier, "childNameA");
	Identifier identifirChild1(identifirChild, "childNameB2");
	Identifier identifirChild2(identifier, "childNameA2");

	Primitive a(71), b(10), c(true);
	Object scope, var, var2;
	string str = "abcdef";


	scope.getObject(identifier) = var;
	scope.getObject(identifirChild) = var2;
	scope.getPrimitive(identifirChild1) = str;

	cout << scope.getObject(identifier) << endl;

	//cout << scope.getObject(identifier)  << endl;

	//cout << scope.getPrimitive(identifirChild1) << endl;
	//scope.removeObject(identifirChild);
	//cout << scope.getPrimitive(identifirChild1) << endl;

	//Variable val(scope.getObject(identifier));
	//cout << val.getObject() << endl;

	//Property prop(str, val);
	//cout << prop << endl;

	PropertyList plist;
	//    plist.add(prop);

	//    Object obliteral = plist.generateObject();
		//cout << obliteral << endl;
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
