﻿#include <iostream>
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
	virtual string stringify(){
	};
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

class XMLArray : public XMLEntity {
	vector <XMLEntity> content;

	XMLArray(vector <XMLEntity> content) {
		this->content = content;
	}
	
	virtual string stringify() override {
		string s;
		for (XMLEntity entity : content) {
			s += entity.stringify();
			return s;
		}
	}
	
};

class XMLSCTag : public XMLTag {

	XMLSCTag(string name, vector <XMLTagParameter> params) {
		this->name = name;
		this->params = params;
	}

	virtual string stringify() override {
		return ("<" + this->name + this->stringify_params() + " />");
	}
};

int main()
{
	
}
