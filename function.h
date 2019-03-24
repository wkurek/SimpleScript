#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
using namespace std;

class Function {
    friend ostream& operator<< (ostream&, Function&);
};

#endif // FUNCTION_H_INCLUDED
