#pragma once
#include "WordTemplate.h"
class WordParagraph :
	public WordTemplate
{
private:
	std::string text;
	bool bold;
	bool italic;
	bool underlined;

public:

	std::string locale();

	virtual std::string stringify() override;

	WordParagraph(std::string text, bool bold, bool italic, bool underlined);

	WordParagraph();
	
	~WordParagraph();
};

/*
class WordParagraph : public WordTemplate {
public:
	string text;
	bool bold;
	bool italic;
	bool underlined;

	WordParagraph() {}

	WordParagraph(string text, bool bold, bool italic, bool underlined) {
		this->text = text;
		this->bold = bold;
		this->italic = italic;
		this->underlined = underlined;
	}

	string locale() {
		string locale = "ru-RU";
		string s_eng = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
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

	virtual string stringify() override {
		StringifyableArray params = StringifyableArray();
		if (this->bold)
			params.add(new XMLSelfClosingTag("w:b"));
		if (this->italic)
			params.add(new XMLSelfClosingTag("w:i"));
		if (this->underlined)
			params.add(new XMLSelfClosingTag("w:u", new vector<XMLTagParameter>{ XMLTagParameter("w:val", "single") }));
		params.add(new XMLSelfClosingTag("w:lang", new vector<XMLTagParameter> { XMLTagParameter("w:val", this->locale()) }));

		return
		(XMLContentTag("w:p",
			new StringifyableArray(new vector<Stringifyable*>{
				new XMLContentTag("w:pPr",
					new XMLContentTag("w:rPr",
						&params)),
				new XMLContentTag("w:r",
					new StringifyableArray(new vector<Stringifyable*>{
						new XMLContentTag("w:rPr",
							&params),
						new XMLContentTag("w:t", new XMLContent(this->text))}))
			}
		)).stringify());
	}

};

*/
