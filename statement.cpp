#include "statement.h"

StatementList::~StatementList() {
    for(std::list<Statement*>::iterator it = this->statements.begin(); it != this->statements.end(); ++it) {
        delete *it;
    }
}
