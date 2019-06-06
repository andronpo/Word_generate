#pragma once
#include "XMLTag.h"

class XMLCustomTag :
	public XMLTag
{
private:
	std::string prefix, suffix;

public:
	
	virtual std::string stringify() override;

	XMLCustomTag(std::string prefix, std::string name, std::vector <XMLTagParameter>* params, std::string suffix);

	XMLCustomTag();

	~XMLCustomTag();
};

