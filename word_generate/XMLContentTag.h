#pragma once
#include "XMLTag.h"
#include "XMLContent.h"


class XMLContentTag :
	public XMLTag
{
public:
	Stringifyable* content;

	XMLContentTag(std::string name, std::vector <XMLTagParameter>* params, Stringifyable* content);

	XMLContentTag(std::string name, Stringifyable* content);

	XMLContentTag(std::string name);

	XMLContentTag(std::string name, std::vector <XMLTagParameter>* params);

	virtual std::string stringify() override;

	XMLContentTag();
	
	~XMLContentTag();
};

/*class XMLContentTag : public XMLTag {
public:
	Stringifyable* content;

	XMLContentTag() {}

	XMLContentTag(string name, vector <XMLTagParameter>* params, Stringifyable* content) {
		this->name = name;
		this->params = params;
		this->content = content;
	}

	XMLContentTag(string name, vector <XMLTagParameter>* params) : XMLContentTag(name, params, new XMLContent("")) {}

	XMLContentTag(string name, Stringifyable* content) : XMLContentTag(name, new vector<XMLTagParameter> {}, content) {}

	XMLContentTag(string name) : XMLContentTag(name, new vector<XMLTagParameter>{}, new XMLContent("")) {}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + ">" + this->content->stringify() + "</" + this->name + ">");
	}
};*/