#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <regex> 
using namespace std;

#include "identifier.h"
#include "exception.h"

#define IDENTIFIER_REGEX "[_a-zA-Z$]([_0-9a-zA-Z])*"

Identifier::Identifier(string properyName) {
    this->propertiesNames.push_back(properyName);
}

Identifier::Identifier(Identifier parent, string childPropertyName) {
    this->propertiesNames = parent.propertiesNames;
    this->propertiesNames.push_back(childPropertyName);
}

Identifier::Identifier(Identifier parent, string childPropertyName, bool quotation) {
	if (quotation) {
		childPropertyName = childPropertyName
			.substr(1, childPropertyName.length() - 2);

		regex identifierRegex(IDENTIFIER_REGEX);

		if (!regex_match(childPropertyName, identifierRegex)) {
			cerr << "[ERROR]\tInvalid identifier: " << childPropertyName << endl;
			throw InvalidIdentifierException(childPropertyName);
		}
	}

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

Identifier::operator std::string() const {
	string str;

	for (int i = 0; i < this->propertiesNames.size(); ++i) {
		str.append(this->propertiesNames[i]);

		if (i < (this->propertiesNames.size() - 1)) {
			str.append(".");
		}
	}

	return str;
}