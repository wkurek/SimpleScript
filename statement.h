#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"

class Object;

class Statement {
public:
    virtual void evaluate(Object) const = 0;
};

class StatementsList {
    list<shared_ptr<Statement>> statements;

public:
    void evaluate(Object);

    void add(shared_ptr<Statement>);
};

#endif // STATEMENT_H_INCLUDED
