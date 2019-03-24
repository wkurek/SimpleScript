#include "identifier.h"

Identifier::Identifier(string properyName) {
    this->propertiesNames.push_back(properyName);
}

Identifier::Identifier(Identifier parent, string childPropertyName) {
    this->propertiesNames = parent.propertiesNames;
    this->propertiesNames.push_back(childPropertyName);
}

Identifier::Identifier(vector<string> properties) {
    this->propertiesNames = properties;
}

string Identifier::getHead() {
    return this->propertiesNames.front();
}

Identifier Identifier::getTail() {
    vector<string> properties = this->propertiesNames;
    properties.erase(properties.begin());

    return Identifier(properties);
}

bool Identifier::hasTail() {
    return this->propertiesNames.size() > 1;
}
