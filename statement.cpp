#include "statement.h"
#include "object.h"
#include "variable.h"

StatementsList::~StatementsList() {
    for(std::list<Statement*>::iterator it = this->statements.begin(); it != this->statements.end(); ++it) {
        delete *it;
    }
}
