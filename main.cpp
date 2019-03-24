#include <iostream>
#include "identifier.h"

#include "object.h"
#include "primitive.h"
#include "function.h"

using namespace std;

int main()
{
    Identifier identifier("parentName");
    Identifier identifirChild(identifier, "childNameA");
    Identifier identifirChild1(identifirChild, "childNameB2");

    Primitive a(71), b(10), c(true);
    Function fun;
    Object scope, var, var2;
    string str = "abcdef";


    scope.getObject(identifier) = var;
    scope.getObject(identifirChild) = var2;
    scope.getPrimitive(identifirChild1) = str;

    cout << scope.getPrimitive(identifirChild) << endl;
    cout << scope.getPrimitive(identifirChild1) << endl;


    return 0;
}
