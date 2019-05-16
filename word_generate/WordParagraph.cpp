#include "WordParagraph.h"



std::string WordParagraph::stringify() {
	return (XMLContentTag("w:p", phrases).stringify());
}


WordParagraph::WordParagraph(StringifyableArray* phrases) {
	this->phrases = phrases;
}

WordParagraph::WordParagraph() {

}

WordParagraph::~WordParagraph()
{
}
