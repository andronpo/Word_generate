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

class XMLCustomTag : public XMLTag {
public:
	string prefix, suffix;
	
	XMLCustomTag() {}

	XMLCustomTag(string prefix, string name, vector <XMLTagParameter>* params, string suffix) {
		this->name = name;
		this->prefix = prefix;
		this->params = params;
		this->suffix = suffix;
	}

	virtual string stringify() override {
		return ("<" + this->prefix + this->name + this->stringify_params() + this->suffix + ">");
	}

};

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

	void clear() {
		this->content->clear();
	}

	virtual string stringify() override {
		string s;
		for (auto entity : *content) {
			s += entity->stringify();
		}
		return s;
	}
};


//                                                 Word Templates

class WordTemplate : public Stringifible{
	virtual string stringify() override {
		return "";
	}
};

class WordBody : public Stringifible {
public:
	StringifibleArray* content = new StringifibleArray();

	WordBody() {}

	WordBody(StringifibleArray* content) {
		this->content = content;
	}

	virtual string stringify() override {
		
		this->content->add(new XMLContentTag("w:sectPr", 
			new StringifibleArray(new vector<Stringifible*>{
				new XMLSelfClosingTag("w:pgSz",
					new vector <XMLTagParameter> { 
						XMLTagParameter("w:w", "11906"),
						XMLTagParameter("w:h", "16838")}),
				new XMLSelfClosingTag("w:pgMar",
					new vector <XMLTagParameter> { 
						XMLTagParameter("w:top", "1134"),
						XMLTagParameter("w:right", "850"),
						XMLTagParameter("w:bottom", "1134"),
						XMLTagParameter("w:left", "1701"),
						XMLTagParameter("w:header", "708"),
						XMLTagParameter("w:footer", "708"),
						XMLTagParameter("w:gutter", "0")}),
				new XMLSelfClosingTag("w:cols", 
					new vector <XMLTagParameter> {
						XMLTagParameter("w:space", "708")}),
				new XMLSelfClosingTag("w:docGrid",
					new vector <XMLTagParameter> {
						XMLTagParameter("w:linePitch", "360")})
			})));

		return 
			StringifibleArray(new vector <Stringifible*>{
				new XMLCustomTag("?", "xml",
					new vector <XMLTagParameter>{
						XMLTagParameter("version", "1.0"),
						XMLTagParameter("encoding", "UTF-8"),
						XMLTagParameter("standalone", "yes"),
					}, "?"),
				new XMLContentTag("w:document",
					new vector <XMLTagParameter>{
						XMLTagParameter("xmlns:wpc", "http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas"),
						XMLTagParameter("xmlns:cx", "http://schemas.microsoft.com/office/drawing/2014/chartex"),
						XMLTagParameter("xmlns:mc", "http://schemas.openxmlformats.org/markup-compatibility/2006"),
						XMLTagParameter("xmlns:o", "urn:schemas-microsoft-com:office:office"),
						XMLTagParameter("xmlns:r", "http://schemas.openxmlformats.org/officeDocument/2006/relationships"),
						XMLTagParameter("xmlns:m", "http://schemas.openxmlformats.org/officeDocument/2006/math"),
						XMLTagParameter("xmlns:v", "urn:schemas-microsoft-com:vml"),
						XMLTagParameter("xmlns:wp14", "http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing"),
						XMLTagParameter("xmlns:wp", "http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"),
						XMLTagParameter("xmlns:w10", "urn:schemas-microsoft-com:office:word"),
						XMLTagParameter("xmlns:w", "http://schemas.openxmlformats.org/wordprocessingml/2006/main"),
						XMLTagParameter("xmlns:w14", "http://schemas.microsoft.com/office/word/2010/wordml"),
						XMLTagParameter("xmlns:w15", "http://schemas.microsoft.com/office/word/2012/wordml"),
						XMLTagParameter("xmlns:w16se", "http://schemas.microsoft.com/office/word/2015/wordml/symex"),
						XMLTagParameter("xmlns:wpg", "http://schemas.microsoft.com/office/word/2010/wordprocessingGroup"),
						XMLTagParameter("xmlns:wpi", "http://schemas.microsoft.com/office/word/2010/wordprocessingInk"),
						XMLTagParameter("xmlns:wne", "http://schemas.microsoft.com/office/word/2012/wordml"),
						XMLTagParameter("xmlns:wps", "http://schemas.microsoft.com/office/word/2010/wordprocessingShape")
					},
					new XMLContentTag("w:body", content)
		) }).stringify();
	}
};

class WordChart : public WordTemplate {
public:
	string name;


	WordChart() {}

	virtual string stringify() override{}
};

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

class WordTable : public WordTemplate {
public:
	int rows, columns;
	vector <WordParagraph*>* content = new vector <WordParagraph*>{};

	WordTable() {}

	WordTable(int rows, int columns, vector<WordParagraph*>* content) {
		this->rows = rows;
		this->columns = columns;
		this->content = content;
	}

	virtual string stringify() override {

		string wide = to_string((int)floor(9905 / columns));
		StringifibleArray table = StringifibleArray();
		StringifibleArray columns_array = StringifibleArray();
		string s;

		table.add(new XMLContentTag("w:tblPr",
			new StringifibleArray(new vector<Stringifible*>{
				new XMLSelfClosingTag("w:tblStyle",
					new vector <XMLTagParameter> { XMLTagParameter("w:val", "TableGrid")}),
				new XMLSelfClosingTag("w:tblW",
					new vector <XMLTagParameter> { XMLTagParameter("w:w", "0"),
						XMLTagParameter("w:type", "auto")}),
				new XMLSelfClosingTag("w:tblLook")
				})));
		for (int column = 0; column < columns; column++) {
			columns_array.add(new XMLSelfClosingTag("w:gridCol",
				new vector <XMLTagParameter>{ XMLTagParameter("w:w", wide) }));
		}     
		table.add(new XMLContentTag("w:tblGrid", &columns_array));

		for (int row = 0; row < this->rows; row++) {
			for (int column = 0; column < this->columns; column++) {
				s += XMLContentTag("w:tc",
					new StringifibleArray(new vector<Stringifible*>{
						new XMLContentTag("w:tcPr", new XMLSelfClosingTag("w:tcW",
							new vector <XMLTagParameter> { XMLTagParameter("w:w", wide), XMLTagParameter("w:type", "dxa") })),
						this->content->at(columns * row + column)
					})).stringify();
				
			}
			table.add(new XMLContentTag("w:tr", new XMLContent(s)));                                 
			s.clear();
		}
		return XMLContentTag("w:tbl", &table).stringify();
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	
	freopen("index.txt", "w", stdout);
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
	//cout << WordParagraph("text", true, false, false).stringify();
	cout << WordTable(1, 3, new vector<WordParagraph*>{
		new WordParagraph("bold", true, false, false),
		new WordParagraph("normal", false, false, false),
		new WordParagraph("italic", false, true, false),
		}).stringify();

	freopen("inde.txt", "w", stdout);
	cout << WordBody(new StringifibleArray
		(new vector <Stringifible*> { 
			new WordParagraph("text", true, false, false) 
		})).stringify();
}
