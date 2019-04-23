#include "XMLTagParameter.h"

XMLTagParameter::XMLTagParameter(std::string key, std::string value) {
	this->key = key;
	this->value = value;
}

std::string XMLTagParameter::stringify() {
	return this->key + "=\"" + this->value + "\"";
}

XMLTagParameter::XMLTagParameter()
{
}


XMLTagParameter::~XMLTagParameter()
{
}
