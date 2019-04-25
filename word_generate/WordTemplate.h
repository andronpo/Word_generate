#pragma once
#include "XMLContent.h"
#include "StringifyableArray.h"
#include "XMLContentTag.h"
#include "XMLSelfClosingTag.h"
#include "XMLCustomTag.h"

class WordTemplate :
	public Stringifyable
{
public:
	virtual std::string stringify() override;

	WordTemplate();
	
	~WordTemplate();
};

