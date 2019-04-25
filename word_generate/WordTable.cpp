#include "WordTable.h"


std::string WordTable::stringify() {

	std::string wide = std::to_string((int)floor(9905 / columns));
	StringifyableArray table = StringifyableArray();
	StringifyableArray columns_array = StringifyableArray();
	std::string s;

	table.add(new XMLContentTag("w:tblPr",
		new StringifyableArray(new std::vector<Stringifyable*>{
			new XMLSelfClosingTag("w:tblStyle",
				new std::vector <XMLTagParameter> { XMLTagParameter("w:val", "TableGrid")}),
			new XMLSelfClosingTag("w:tblW",
				new std::vector <XMLTagParameter> { XMLTagParameter("w:w", "0"),
					XMLTagParameter("w:type", "auto")}),
			new XMLSelfClosingTag("w:tblLook")
			})));
	for (int column = 0; column < columns; column++) {
		columns_array.add(new XMLSelfClosingTag("w:gridCol",
			new std::vector <XMLTagParameter>{ XMLTagParameter("w:w", wide) }));
	}
	table.add(new XMLContentTag("w:tblGrid", &columns_array));

	for (int row = 0; row < this->rows; row++) {
		for (int column = 0; column < this->columns; column++) {
			s += XMLContentTag("w:tc",
				new StringifyableArray(new std::vector<Stringifyable*>{
					new XMLContentTag("w:tcPr", new XMLSelfClosingTag("w:tcW",
						new std::vector <XMLTagParameter> { XMLTagParameter("w:w", wide), XMLTagParameter("w:type", "dxa") })),
					this->content->at(columns * row + column)
					})).stringify();

		}
		table.add(new XMLContentTag("w:tr", new XMLContent(s)));
		s.clear();
	}
	return XMLContentTag("w:tbl", &table).stringify();
}


WordTable::WordTable(int rows, int columns, std::vector<WordParagraph*>* content) {
	this->rows = rows;
	this->columns = columns;
	this->content = content;
}


WordTable::WordTable()
{
}


WordTable::~WordTable()
{
}
