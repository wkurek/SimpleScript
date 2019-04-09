#include <iostream>
#include "identifier.h"

#include "object.h"
#include "primitive.h"
#include "function.h"
#include "variable.h"

using namespace std;

int main()
{
    Identifier identifier("parentName");
    Identifier identifirChild(identifier, "childNameA");
    Identifier identifirChild1(identifirChild, "childNameB2");
    Identifier identifirChild2(identifier, "childNameA2");

    Primitive a(71), b(10), c(true);
    Function fun;
    Object scope, var, var2;
    string str = "abcdef";


    scope.getObject(identifier) = var;
    scope.getObject(identifirChild) = var2;
    scope.getPrimitive(identifirChild1) = str;
    scope.getFunction(identifirChild2) = fun;

    cout << scope.getObject(identifier)  << endl;

    //cout << scope.getPrimitive(identifirChild1) << endl;
    //scope.removeObject(identifirChild);
    //cout << scope.getPrimitive(identifirChild1) << endl;

    Variable val(scope.getObject(identifier));
    cout << val.getObject();
    return 0;
}
