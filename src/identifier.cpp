#include <include/identifier.h>

Identifier::Identifier()
{
}

Identifier::Identifier(string baseName)
{
    this->names = {baseName};
}

Identifier::Identifier(const Identifier parent, string baseName)
{
    this->names = vector<string>(parent.names.begin(), parent.names.end());
    this->names.push_back(baseName);
}

string Identifier::getHead()
{
    return this->names.front();
}

Identifier Identifier::getTail()
{
    Identifier identifier;

    for (int i = 1; i < this->names.size(); ++i)
    {
        identifier.names.push_back(this->names[i]);
    }

    return identifier;
}

bool Identifier::hasTail()
{
    return this->names.size() > 1;
}