#include "XMLSelfClosingTag.h"




std::string XMLSelfClosingTag::stringify() {
	return ("<" + this->name + this->stringify_params() + "/>");
}


XMLSelfClosingTag::XMLSelfClosingTag(std::string name, std::vector <XMLTagParameter>* params) {
	this->name = name;
	this->params = params;
}

XMLSelfClosingTag::XMLSelfClosingTag(std::string name) : XMLSelfClosingTag(name, new std::vector <XMLTagParameter>{}) {}

XMLSelfClosingTag::XMLSelfClosingTag()
{
}


XMLSelfClosingTag::~XMLSelfClosingTag()
{
}
