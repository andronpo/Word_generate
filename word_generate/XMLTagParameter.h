#pragma once
#include <string>

class XMLTagParameter
{
public:

	std::string key;
	std::string value;

	XMLTagParameter(std::string key, std::string value);

	std::string stringify();

	XMLTagParameter();

	~XMLTagParameter();
};