#ifndef IDENTIFIER_H_INCLUDED
#define IDENTIFIER_H_INCLUDED

#include <vector>
#include <string>
using namespace std;

class Identifier {
    vector<string> propertiesNames;

    Identifier(vector<string>);

public:
    Identifier(string);
    Identifier(Identifier, string);

    string getHead();
    Identifier getTail();
    bool hasTail();
};

#endif // IDENTIFIER_H_INCLUDED

