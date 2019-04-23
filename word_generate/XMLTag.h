#pragma once
#include "Stringifyable.h"
#include <vector>
#include "XMLTagParameter.h"

class XMLTag :
	public Stringifyable
{
public:
	std::string name;
	std::vector <XMLTagParameter>* params = new std::vector<XMLTagParameter>{};

	virtual std::string stringify_params();
	
	XMLTag(std::string name, std::vector <XMLTagParameter>* params);

	XMLTag();

	~XMLTag();
};

/*class XMLTag : public Stringifyable {
public:
	string name;
	vector <XMLTagParameter>* params = new vector<XMLTagParameter> {};

	XMLTag() {}

	XMLTag(string name, vector <XMLTagParameter>*params) {
		this->name = name;
		this->params = params;
	}
	
	virtual string stringify_params() {
		string s = "";
		for (XMLTagParameter param : *params){
			s += " " + param.stringify();
		}
		return (s);
	}
};*/