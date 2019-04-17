#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <list>

#include "object.h"

class Statement {
public:
    virtual void evaluate(Object) const = 0;
};

class StatementList {
    list<Statement*> statements;

public:
    ~StatementList();

    void add(Statement*);
};

#endif // STATEMENT_H_INCLUDED
