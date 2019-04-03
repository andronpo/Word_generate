#include <iostream>
#include <vector>

using namespace std;

class XMLTagParams {
	string key;
	string value;
public:
	string stringify() {
		return " " + key + "=\"" + value + "\"";
	}

};

class XMLEntity {
public:
	virtual string stringify() {};
};

class XMLContent : public XMLEntity {
	string content;

	XMLContent() {}

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
	vector <XMLTagParams> params;
	virtual string stringify_params() {
		string s;
		for (XMLTagParams param : this->params)
			s += " " + param.stringify();
		return (params.empty() ? "" : s);
	}
};

class XMLContentTag : public XMLTag {
	XMLEntity content;
	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + ">" + this->content.stringify() + "</" + this->name + ">");
	}
};

class XMLSCTag : public XMLTag {

};

int main()
{
    cout << "Hello World!\n"; 
}
