#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"

void StatementsList::add(shared_ptr<Statement> statementPtr) {
    this->statements.push_back(statementPtr);
}

void StatementsList::evaluate(Object scope) {
    for(auto it = this->statements.begin(); it != this->statements.end(); ++it) {
        (*it)->evaluate(scope);
    }
}
