#include "WordParagraph.h"


std::string WordParagraph::locale() {
	std::string locale = "ru-RU";
	std::string s_eng = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	for (unsigned int i = 0; i < this->text.length(); i++)
	{
		for (unsigned int j = 0; j < s_eng.length(); j++)
		{
			if (this->text[i] == s_eng[j])
			{
				locale = "en-US";
			}
		}
	}
	return locale;
}


std::string WordParagraph::stringify() {
	StringifyableArray params = StringifyableArray();
	if (this->bold)
		params.add(new XMLSelfClosingTag("w:b"));
	if (this->italic)
		params.add(new XMLSelfClosingTag("w:i"));
	if (this->underlined)
		params.add(new XMLSelfClosingTag("w:u", new std::vector<XMLTagParameter>{ XMLTagParameter("w:val", "single") }));
	params.add(new XMLSelfClosingTag("w:lang", new std::vector<XMLTagParameter>{ XMLTagParameter("w:val", this->locale()) }));

	return
		(XMLContentTag("w:p",
			new StringifyableArray(new std::vector<Stringifyable*>{
				new XMLContentTag("w:pPr",
					new XMLContentTag("w:rPr",
						&params)),
				new XMLContentTag("w:r",
					new StringifyableArray(new std::vector<Stringifyable*>{
						new XMLContentTag("w:rPr",
							&params),
						new XMLContentTag("w:t", new XMLContent(this->text))}))
				}
	)).stringify());
}


WordParagraph::WordParagraph(std::string text, bool bold, bool italic, bool underlined) {
	this->text = text;
	this->bold = bold;
	this->italic = italic;
	this->underlined = underlined;
}


WordParagraph::WordParagraph()
{
}


WordParagraph::~WordParagraph()
{
}
