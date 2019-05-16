#pragma once
#include "WordTemplate.h"

class WordPhrase :
	public WordTemplate
{
public:
	std::string text;
	bool bold;
	bool italic;
	bool underlined;

	std::string locale();

	virtual std::string stringify() override;

	WordPhrase(std::string text, bool bold, bool italic, bool underlined);

	WordPhrase();

	~WordPhrase();
};

