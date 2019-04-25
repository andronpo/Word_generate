#include "XMLContentTag.h"


std::string XMLContentTag::stringify() {
	return ("<" + this->name + this->stringify_params() + ">" + this->content->stringify() + "</" + this->name + ">");
}


XMLContentTag::XMLContentTag(std::string name, std::vector <XMLTagParameter>* params, Stringifyable* content) {
	this->name = name;
	this->params = params;
	this->content = content;
}

XMLContentTag::XMLContentTag(std::string name, std::vector <XMLTagParameter>* params) : XMLContentTag(name, params, new XMLContent("")) {}

XMLContentTag::XMLContentTag(std::string name, Stringifyable* content) : XMLContentTag(name, new std::vector<XMLTagParameter>{}, content) {}

XMLContentTag::XMLContentTag(std::string name) : XMLContentTag(name, new std::vector<XMLTagParameter>{}, new XMLContent("")) {}

XMLContentTag::XMLContentTag()
{
}


XMLContentTag::~XMLContentTag()
{
}
