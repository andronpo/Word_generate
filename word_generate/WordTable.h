#pragma once
#include "WordTemplate.h"
#include "WordParagraph.h"

class WordTable :
	public WordTemplate
{
public:
	int rows, columns;
	std::vector <WordParagraph*>* content = new std::vector <WordParagraph*>{};

	virtual std::string stringify() override;

	WordTable(int rows, int columns, std::vector<WordParagraph*>* content);

	WordTable();
	
	~WordTable();
};