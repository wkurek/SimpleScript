#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <list>

#include "object.h"
#include "variable.h"

class Object;

class Statement {
public:
    virtual void evaluate(Object) const = 0;
};

class StatementsList {
    list<Statement*> statements;

public:
    ~StatementsList();

    void add(Statement*);
};

#endif // STATEMENT_H_INCLUDED
