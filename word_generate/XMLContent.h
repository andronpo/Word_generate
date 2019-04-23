#pragma once
#include "Stringifyable.h"

class XMLContent :
	public Stringifyable
{
	std::string content;

public:

	XMLContent(std::string content);

	virtual std::string stringify() override;

	XMLContent();

	~XMLContent();
};

