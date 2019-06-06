#pragma once
#include <string>

class XMLTagParameter
{
private:

	std::string key;
	std::string value;

public:

	XMLTagParameter(std::string key, std::string value);

	std::string stringify();

	XMLTagParameter();

	~XMLTagParameter();
};