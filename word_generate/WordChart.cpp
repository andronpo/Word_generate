#include "WordChart.h"



std::string WordChart::stringify() {
	return XMLContentTag("w:p",
		new XMLContentTag("w:r",
			new StringifyableArray(new std::vector <Stringifyable*>{
				new XMLContentTag("w:rPr",
					new XMLSelfClosingTag("w:noProof")
				),
				new XMLContentTag("w:drawing",
					new XMLContentTag("wp:inline",
						new std::vector <XMLTagParameter>{
							XMLTagParameter("distT", "0"),
							XMLTagParameter("distB", "0"),
							XMLTagParameter("distL", "0"),
							XMLTagParameter("distR", "0")
						},
						new StringifyableArray(new std::vector <Stringifyable*>{
							new XMLSelfClosingTag("wp:extent",
								new std::vector <XMLTagParameter>{
									XMLTagParameter("cx", size_x),
									XMLTagParameter("cy", size_y)
								}),

							new XMLSelfClosingTag("wp:effectExtent",
								new std::vector <XMLTagParameter>{
									XMLTagParameter("l", "0"),
									XMLTagParameter("t", "0"),
									XMLTagParameter("r", "19050"),
									XMLTagParameter("b", "19050")
								}),

							new XMLSelfClosingTag("wp:docPr",
								new std::vector <XMLTagParameter>{
									XMLTagParameter("id", name),
									XMLTagParameter("name", "Chart " + name)
								}),

							new XMLSelfClosingTag("wp:cNvGraphicFramePr"),

							new XMLContentTag("a:graphic",
								new std::vector <XMLTagParameter>{
									XMLTagParameter("xmlns:a", "http://schemas.openxmlformats.org/drawingml/2006/main")
								},
								new XMLContentTag("a:graphicData",
									new std::vector <XMLTagParameter>{
										XMLTagParameter("uri", "http://schemas.openxmlformats.org/drawingml/2006/chart"),
									},
									new XMLSelfClosingTag("c:chart",
										new std::vector <XMLTagParameter>{
											XMLTagParameter("xmlns:c", "http://schemas.openxmlformats.org/drawingml/2006/chart"),
											XMLTagParameter("xmlns:r", "http://schemas.openxmlformats.org/officeDocument/2006/relationships"),
											XMLTagParameter("r:id", id),
										})
								)

							)
						})))
				}))).stringify();
}


WordChart::WordChart(std::string id, std::string name, std::string size_x, std::string size_y) {
	this->id = id;
	this->name = name;
	this->size_x = size_x;
	this->size_y = size_y;
}


WordChart::WordChart()
{
}


WordChart::~WordChart()
{
}
