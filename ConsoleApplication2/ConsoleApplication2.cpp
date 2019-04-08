#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Stringifible {
public:
	virtual string stringify() {
		return "f";
	}
};



class XMLTagParameter {
	string key;
	string value;
public:
	XMLTagParameter(string key, string value) {
		this->key = key;
		this->value = value;
	}

	XMLTagParameter() {	}

	string stringify() {
		return key + "=\"" + value + "\"";
	}

};

class XMLContent : public Stringifible {
public:
	string content;

	XMLContent(string content) {
		this->content = content;
	}

	 virtual string stringify() override {
		 return this->content;
	}
};

class XMLTag : public Stringifible {
public:
	string name;
	vector <XMLTagParameter>* params = new vector<XMLTagParameter> {};

	XMLTag() {}

	XMLTag(string name, vector <XMLTagParameter>*params) {
		this->name = name;
		this->params = params;
	}
	
	virtual string stringify_params() {
		string s = "";
		for (XMLTagParameter param : *params){
			s += " " + param.stringify();
		}
		return (s);
	}
};

class XMLContentTag : public XMLTag {
public:
	Stringifible* content;

	XMLContentTag() {}

	XMLContentTag(string name, vector <XMLTagParameter>* params, Stringifible* content) {
		this->name = name;
		this->params = params;
		this->content = content;
	}

	XMLContentTag(string name, vector <XMLTagParameter>* params) : XMLContentTag(name, params, new XMLContent("")) {}

	XMLContentTag(string name, Stringifible* content) : XMLContentTag(name, new vector<XMLTagParameter> {}, content) {}

	XMLContentTag(string name) : XMLContentTag(name, new vector<XMLTagParameter>{}, new XMLContent("")) {}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + ">" + this->content->stringify() + "</" + this->name + ">");
	}
};

class XMLSelfClosingTag : public XMLTag {
public:
	XMLSelfClosingTag() {}

	

	XMLSelfClosingTag(string name, vector <XMLTagParameter>* params) {
		this->name = name;
		this->params = params;
	}

	XMLSelfClosingTag(string name) : XMLSelfClosingTag(name, new vector <XMLTagParameter>{}) {}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + "/>");
	}
};


//                                                 Word Templates


class StringifibleArray : public Stringifible {
public: 
	vector <Stringifible*>* content = new vector <Stringifible*>{};
	
	StringifibleArray() {}

	StringifibleArray(vector <Stringifible*>* content) {
		this->content = content;
	}

	StringifibleArray add(Stringifible* element) {
		this->content->push_back(element);
		return *this;
	}

	virtual string stringify() override{
		string s;
		for (auto entity : *content) {
			s += entity->stringify();
		}
		return s;
	}
};


class WordChart : public Stringifible {
public:

	WordChart() {}

	
};

class WordParagraph : public Stringifible {
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

	string stringify() {
		StringifibleArray params = StringifibleArray();
		if (this->bold)
			params.add(new XMLSelfClosingTag("w:b"));
		if (this->italic)
			params.add(new XMLSelfClosingTag("w:i"));
		if (this->underlined)
			params.add(new XMLSelfClosingTag("w:u", new vector<XMLTagParameter>{ XMLTagParameter("w:val", "single") }));
		params.add(new XMLSelfClosingTag("w:lang", new vector<XMLTagParameter> { XMLTagParameter("w:val", this->locale()) }));
		
		return 
		(XMLContentTag("w:p", 
			new StringifibleArray(new vector<Stringifible*>{
				new XMLContentTag("w:pPr", 
					new XMLContentTag("w:rPr", 
						&params)), 
				new XMLContentTag("w:r",
					new StringifibleArray(new vector<Stringifible*>{
						new XMLContentTag("w:rPr",
							&params),
						new XMLContentTag("w:t", new XMLContent(this->text))}))
			}
		)).stringify());
	}

};

class WordTable : public Stringifible {
public:
	int rows, columns;
	vector <WordParagraph*>* content = new vector <WordParagraph*>{};


	WordTable() {}

	WordTable(int rows, int columns, vector<WordParagraph*>* content) {
		this->rows = rows;
		this->columns = columns;
		this->content = content;
	}

	string stringify() {
		int wide = floor(9905 / columns);
		string s_wide = to_string(wide);
		string s;
		for (int row = 0; row < this->rows; row++) {
			for (int column = 0; column < this->columns; column++) {
				s += XMLContentTag("w:tc",
					new StringifibleArray(new vector<Stringifible*>{
						new XMLContentTag("w:tcPr", new XMLSelfClosingTag("w:tcW",
							new vector <XMLTagParameter> { XMLTagParameter("w:w", s_wide), XMLTagParameter("w:type", "dxa") })),
						this->content->at(columns * row + column)
					})).stringify();
			}

		}
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	
	//freopen("index.html", "w", stdout);
	//XMLContent content("CONTENT"), content1("content");
	/*
	cout << XMLContentTag(string("TAG1"),
		vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") },
		& XMLArray(&vector <XMLEntity*> {&content1, & XMLSCTag("tagsc", vector <XMLTagParameter> {XMLTagParameter("key", "value")})})).stringify() << endl;
	cout << XMLContentTag(string("TAG1"), vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") }, & content).stringify() << endl;

	cout << XMLSelfClosingTag("name", vector <XMLTagParameter> {}).stringify() << endl;
	cout << XMLSelfClosingTag(string("TAG1"), vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") }).stringify();
	cout << XMLSelfClosingTag(string("TAG2"), vector <XMLTagParameter> {}).stringify();
	
	cout << endl << XMLContentTag("html",
		new XMLArray(new vector<XMLEntity*>{
			new XMLContentTag("head",
				new XMLArray(new vector<XMLEntity*>{
					new XMLContentTag("title", new XMLContent("Title of the page")),
					new XMLContentTag("link", new vector<XMLTagParameter>{ XMLTagParameter("rel", "stylesheet"), XMLTagParameter("href", "./styles.css") }),
					new XMLContentTag("link", new vector<XMLTagParameter>{ XMLTagParameter("icon", "./favicon.ico") })
				})
			),
			new XMLContentTag("body",
				new XMLContent("CONTENT")
			)
		})
	).stringify();
	*/
	cout << WordParagraph("text", true, false, false).stringify();
}
