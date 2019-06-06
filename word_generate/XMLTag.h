#pragma once
#include "Stringifyable.h"
#include <vector>
#include "XMLTagParameter.h"

class XMLTag :
	public Stringifyable
{
protected:

	std::string name;
	std::vector <XMLTagParameter>* params = new std::vector<XMLTagParameter>{};

public:

	virtual std::string stringify_params();
	
	XMLTag(std::string name, std::vector <XMLTagParameter>* params);

	XMLTag();

	~XMLTag();
};
