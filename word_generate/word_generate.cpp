#include <iostream>
#include <stdio.h>
#include "WordTable.h"
#include "WordBody.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	
	freopen("document.xml", "w", stdout);
	
	cout << WordBody(new StringifyableArray
	(new vector <Stringifyable*>{
			new WordParagraph("text", true, false, false),
			new WordTable(1, 3, new vector<WordParagraph*>{
				new WordParagraph("bold", true, false, false),
				new WordParagraph("normal", false, false, false),
				new WordParagraph("italic", false, true, false),
			})
		})).stringify();
}
