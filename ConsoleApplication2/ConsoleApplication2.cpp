#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;



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

class XMLEntity {
public:
	virtual string stringify() {
		return "foo";
	}
};

class XMLContent : public XMLEntity {
public:
	string content;

	XMLContent(string content) {
		this->content = content;
	}

	 virtual string stringify() override {
		 return this->content;
	}
};

class XMLTag : public XMLEntity {
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
		for (XMLTagParameter param : *params)
		{
			s += " " + param.stringify();
		}
		return (s);
	}
};

class XMLContentTag : public XMLTag {
public:
	XMLEntity* content;

	XMLContentTag() {}

	XMLContentTag(string name, vector <XMLTagParameter>* params, XMLEntity* content) {
		this->name = name;
		this->params = params;
		this->content = content;
	}

	XMLContentTag(string name, vector <XMLTagParameter>* params) : XMLContentTag(name, params, new XMLContent("")) {}

	XMLContentTag(string name, XMLEntity* content) : XMLContentTag(name, new vector<XMLTagParameter> {}, content) {}

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

class XMLArray : public XMLEntity {
public:
	vector <XMLEntity*>* content = new vector<XMLEntity*>{};

	XMLArray() {}

	XMLArray(vector <XMLEntity*> *content) {
		this->content = content;
	}


	XMLArray add(XMLEntity* element) {
		this->content->push_back(element);
		return *this;
	}

	virtual string stringify() override {
		string s;
		for (auto entity : *content) 
		{
			s += entity->stringify();
		}
		return s;
	}
	
};


//                                                 Word Templates

class WordEntity {
public:
	string stringify() {
		return "fo";
	}
};

class WordParagraph : public XMLEntity {
public: 
	string text;
	bool bold; 
	bool italic;
	bool underlined;

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
		XMLArray params = XMLArray();
		if (this->bold)
			params.add(new XMLSelfClosingTag("w:b"));
		if (this->italic)
			params.add(new XMLSelfClosingTag("w:i"));
		if (this->underlined)
			params.add(new XMLSelfClosingTag("w:u", new vector<XMLTagParameter>{ XMLTagParameter("w:val", "single") }));
		params.add(new XMLSelfClosingTag("w:lang", new vector<XMLTagParameter> { XMLTagParameter("w:val", this->locale()) }));
		
		return 
		(XMLContentTag("w:p", 
			new XMLArray(new vector<XMLEntity*>{
				new XMLContentTag("w:pPr", 
					new XMLContentTag("w:rPr", 
						&params)), 
				new XMLContentTag("w:r",
					new XMLArray(new vector<XMLEntity*>{
						new XMLContentTag("w:rPr",
							&params),
						new XMLContentTag("w:t", new XMLContent(this->text))}))
			}
		)).stringify());
	}

};




int main()
{
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
