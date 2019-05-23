#include <iostream>
#include <stdio.h>
#include "WordBody.h"
//#include "Parser.cpp"

std::vector <Stringifyable*>* phrases = new std::vector<Stringifyable*>;

void parser() {
	int flag = 0;       //0 - нет спецсимволов, 1 - *, 2 - **, 3 - ***, -4 - ~, -3 - ~*, -2 - ~**, -1 - ~***
	std::string current, buffer;
	while (getline(std::cin, current)) {
		for (int i = 0; i < current.length(); i++) {
			if (current[i] == '*' && buffer.empty()) {
				flag++;
			}
			else if (current[i] == '~' && buffer.empty()) {
				flag -= 4;
			}
			else if ((current[i] == '*' || current[i] == '~') && !buffer.empty()) {
				while ((current[i] == '*' && current[i] == '~')) {
					i++;
				}
				switch (flag) {
				case 0:
					phrases->push_back(new WordPhrase(buffer, 0, 0, 0));
					break;
				case 1:
					phrases->push_back(new WordPhrase(buffer, 1, 0, 0));
					break;
				case 2:
					phrases->push_back(new WordPhrase(buffer, 0, 1, 0));
					break;
				case 3:
					phrases->push_back(new WordPhrase(buffer, 1, 1, 0));
					break;
				case -1:
					phrases->push_back(new WordPhrase(buffer, 1, 1, 1));
					break;
				case -2:
					phrases->push_back(new WordPhrase(buffer, 0, 1, 1));
					break;
				case -3:
					phrases->push_back(new WordPhrase(buffer, 1, 0, 1));
					break;
				case -4:
					phrases->push_back(new WordPhrase(buffer, 0, 0, 1));
					break;
				}
				buffer.clear();
				i--;
			}

			else {
				buffer += current[i];
			}
		}
	}
}


int main()
{
	freopen("document.xml", "w", stdout);
	setlocale(LC_ALL, "Russian");
	
	

	parser();
	std::cout << WordBody(new StringifyableArray 
		(new std::vector <Stringifyable*>{
			new WordParagraph(new StringifyableArray(phrases))
		})).stringify();




	// Sample
	/*
	freopen("document1.txt", "w", stdout);
	std::cout << WordBody(new StringifyableArray
		(new std::vector <Stringifyable*>{
			new WordParagraph(new StringifyableArray(new std::vector<Stringifyable*>{new WordPhrase("text", 0, 0, 0),
				})),
		})).stringify();
	*/
}






/*new WordTable(1, 3, new std::vector<WordParagraph*>{
				new WordParagraph(new StringifyableArray(new std::vector<Stringifyable*>{new WordPhrase("bold", true, false, false)})),
				new WordParagraph(new StringifyableArray(new std::vector<Stringifyable*>{new WordPhrase("normal", true, false, false)})),
				new WordParagraph(new StringifyableArray(new std::vector<Stringifyable*>{new WordPhrase("italic", false, true, false)})),
			})*/