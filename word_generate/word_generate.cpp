#include <iostream>
#include <stdio.h>
#include "WordTable.h"
#include "WordBody.h"


using namespace std;




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
	cout << WordBody(new StringifyableArray
	(new vector <Stringifyable*>{
			new WordParagraph("text", true, false, false),
			//new WordChart("rId5", "1")
		})).stringify();
}
