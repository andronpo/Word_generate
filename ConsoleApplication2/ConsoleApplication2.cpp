#include <iostream>
#include <vector>

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
		return " " + key + "=\"" + value + "\"";
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
	vector <XMLTagParameter> params;

	XMLTag() {}

	XMLTag(string name, vector <XMLTagParameter> params) {
		this->name = name;
		this->params = params;
	}
	
	virtual string stringify_params() {
		string s;
		for (XMLTagParameter param : this->params)
			s += " " + param.stringify();
		return (params.empty() ? "" : s);
	}
};

class XMLContentTag : public XMLTag {
public:
	XMLEntity *content;
	
	XMLContentTag() {}

	XMLContentTag(string name, vector <XMLTagParameter> params, XMLEntity* content) {
		this->name = name;
		this->params = params;
		this->content = content;
	}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + ">" + this->content->stringify() + "</" + this->name + ">");
	}
};

class XMLSCTag : public XMLTag {
public:
	XMLSCTag() {}

	XMLSCTag(string name, vector <XMLTagParameter> params) {
		this->name = name;
		this->params = params;
	}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + "/>");
	}
};

class XMLArray : public XMLEntity {
public:
	vector <XMLEntity*> *content;

	XMLArray() {}

	XMLArray(vector <XMLEntity*> *content) {
		this->content = content;
	}
	
	virtual string stringify() override {
		string s;
		for (auto entity : *content) {
			s += entity->stringify();
		}
		return s;
	}
	
};


int main()
{
	XMLContent content("CONTENT"), content1("content");
	
	cout << XMLContentTag(string("TAG1"),
		vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") },
		& XMLArray(&vector <XMLEntity*> {&content1, & XMLSCTag("tagsc", vector <XMLTagParameter> {XMLTagParameter("key", "value")})})).stringify() << endl;
	cout << XMLContentTag(string("TAG1"), vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") }, & content).stringify() << endl;
	
	cout << XMLSCTag("name", vector <XMLTagParameter> {}).stringify() << endl;
	cout << XMLSCTag(string("TAG1"), vector <XMLTagParameter> { XMLTagParameter("KEY", "VALUE") }).stringify();
}
