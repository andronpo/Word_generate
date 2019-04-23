#pragma once
#include "Stringifyable.h"
#include <vector>

class StringifyableArray :
	public Stringifyable
{

	std::vector <Stringifyable*>* content = new std::vector <Stringifyable*>{};

public:

	StringifyableArray(std::vector <Stringifyable*>* content);

	StringifyableArray add(Stringifyable* element);

	void clear();

	virtual std::string stringify() override;
	
	StringifyableArray();
	
	~StringifyableArray();
};

