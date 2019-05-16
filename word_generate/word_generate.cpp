#include <iostream>
#include <stdio.h>
#include "WordTable.h"
#include "WordBody.h"



using namespace std;




int main()
{
	setlocale(LC_ALL, "Russian");
	
	freopen("index.txt", "w", stdout);
	
	

	cout << WordTable(1, 3, new vector<WordParagraph*>{
		new WordParagraph(new StringifyableArray(new vector<Stringifyable*>{new WordPhrase("bold", true, false, false)})),
		new WordParagraph(new StringifyableArray(new vector<Stringifyable*>{new WordPhrase("normal", true, false, false)})),
		new WordParagraph(new StringifyableArray(new vector<Stringifyable*>{new WordPhrase("italic", false, true, false)})),
		}).stringify();

	freopen("inde.txt", "w", stdout);
	cout << WordBody(new StringifyableArray
	(new vector <Stringifyable*>{
			new WordParagraph(new StringifyableArray(new vector<Stringifyable*>{new WordPhrase("bold", true, false, false)})),
			//new WordChart("rId5", "1")
		})).stringify();
}
