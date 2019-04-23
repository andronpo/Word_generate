#include "XMLTag.h"

std::string XMLTag::stringify_params() {
	std::string s = "";
	for (XMLTagParameter param : *params) {
		s += " " + param.stringify();
	}
	return (s);
}


XMLTag::XMLTag(std::string name, std::vector <XMLTagParameter>* params) {
	this->name = name;
	this->params = params;
}


XMLTag::XMLTag()
{
}


XMLTag::~XMLTag()
{
}
