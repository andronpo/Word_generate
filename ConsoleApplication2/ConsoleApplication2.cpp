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
	virtual string stringify() {};
};

class XMLContent : XMLEntity {
	string content;

	XMLContent() {}

	XMLContent(string content) {
		this->content = content;
	}

	 virtual string stringify() override {
		 return this->content;
	}
};




class XMLTag : XMLEntity {
	string name;
	vector <XMLTagParams> params;
	virtual string stringify_params() {
		string s;
		for (XMLTagParams param : params)
			s += " " + param.stringify();
		return s;
	}
};



int main()
{
    cout << "Hello World!\n"; 
}
