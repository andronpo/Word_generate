#pragma once
#include "Stringifyable.h"

class XMLContent :
	public Stringifyable
{
protected:
	std::string content;

public:

	XMLContent(std::string content);

	virtual std::string stringify() override;

	XMLContent();

	~XMLContent();
};

