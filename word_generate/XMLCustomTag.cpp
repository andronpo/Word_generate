#include "XMLCustomTag.h"


std::string XMLCustomTag::stringify() {
	return ("<" + this->prefix + this->name + this->stringify_params() + this->suffix + ">");
}


XMLCustomTag::XMLCustomTag(std::string prefix, std::string name, std::vector <XMLTagParameter>* params, std::string suffix) {
	this->name = name;
	this->prefix = prefix;
	this->params = params;
	this->suffix = suffix;
}


XMLCustomTag::XMLCustomTag()
{
}


XMLCustomTag::~XMLCustomTag()
{
}
