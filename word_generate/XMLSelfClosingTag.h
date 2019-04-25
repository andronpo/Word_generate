#pragma once
#include "XMLTag.h"


class XMLSelfClosingTag :
	public XMLTag
{
public:

	virtual std::string stringify() override;

	XMLSelfClosingTag(std::string name, std::vector <XMLTagParameter>* params);

	XMLSelfClosingTag(std::string name);

	XMLSelfClosingTag();

	~XMLSelfClosingTag();
};

/*
class XMLSelfClosingTag : public XMLTag {
public:
	XMLSelfClosingTag() {}

	XMLSelfClosingTag(string name, vector <XMLTagParameter>* params) {
		this->name = name;
		this->params = params;
	}

	XMLSelfClosingTag(string name) : XMLSelfClosingTag(name, new vector <XMLTagParameter>{}) {}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + "/>");
	}
};
*/
