#include "WordBody.h"


std::string WordBody::stringify() {
	this->content->add(new XMLContentTag("w:sectPr",
		new StringifyableArray(new std::vector<Stringifyable*>{
			new XMLSelfClosingTag("w:pgSz",
				new std::vector <XMLTagParameter> {
					XMLTagParameter("w:w", "11906"),
					XMLTagParameter("w:h", "16838")}),
			new XMLSelfClosingTag("w:pgMar",
				new std::vector <XMLTagParameter> {
					XMLTagParameter("w:top", "1134"),
					XMLTagParameter("w:right", "850"),
					XMLTagParameter("w:bottom", "1134"),
					XMLTagParameter("w:left", "1701"),
					XMLTagParameter("w:header", "708"),
					XMLTagParameter("w:footer", "708"),
					XMLTagParameter("w:gutter", "0")}),
			new XMLSelfClosingTag("w:cols",
				new std::vector <XMLTagParameter> {
					XMLTagParameter("w:space", "708")}),
			new XMLSelfClosingTag("w:docGrid",
				new std::vector <XMLTagParameter> {
					XMLTagParameter("w:linePitch", "360")})
			})));

	return
		StringifyableArray(new std::vector <Stringifyable*>{
			new XMLCustomTag("?", "xml",
				new std::vector <XMLTagParameter>{
					XMLTagParameter("version", "1.0"),
					XMLTagParameter("encoding", "UTF-8"),
					XMLTagParameter("standalone", "yes"),
				}, "?"),
			new XMLContentTag("w:document",
				new std::vector <XMLTagParameter>{
					XMLTagParameter("xmlns:wpc", "http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas"),
					XMLTagParameter("xmlns:cx", "http://schemas.microsoft.com/office/drawing/2014/chartex"),
					XMLTagParameter("xmlns:mc", "http://schemas.openxmlformats.org/markup-compatibility/2006"),
					XMLTagParameter("xmlns:o", "urn:schemas-microsoft-com:office:office"),
					XMLTagParameter("xmlns:r", "http://schemas.openxmlformats.org/officeDocument/2006/relationships"),
					XMLTagParameter("xmlns:m", "http://schemas.openxmlformats.org/officeDocument/2006/math"),
					XMLTagParameter("xmlns:v", "urn:schemas-microsoft-com:vml"),
					XMLTagParameter("xmlns:wp14", "http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing"),
					XMLTagParameter("xmlns:wp", "http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"),
					XMLTagParameter("xmlns:w10", "urn:schemas-microsoft-com:office:word"),
					XMLTagParameter("xmlns:w", "http://schemas.openxmlformats.org/wordprocessingml/2006/main"),
					XMLTagParameter("xmlns:w14", "http://schemas.microsoft.com/office/word/2010/wordml"),
					XMLTagParameter("xmlns:w15", "http://schemas.microsoft.com/office/word/2012/wordml"),
					XMLTagParameter("xmlns:w16se", "http://schemas.microsoft.com/office/word/2015/wordml/symex"),
					XMLTagParameter("xmlns:wpg", "http://schemas.microsoft.com/office/word/2010/wordprocessingGroup"),
					XMLTagParameter("xmlns:wpi", "http://schemas.microsoft.com/office/word/2010/wordprocessingInk"),
					XMLTagParameter("xmlns:wne", "http://schemas.microsoft.com/office/word/2012/wordml"),
					XMLTagParameter("xmlns:wps", "http://schemas.microsoft.com/office/word/2010/wordprocessingShape")
				},
				new XMLContentTag("w:body", content)
	) }).stringify();
}


WordBody::WordBody(StringifyableArray* content) {
	this->content = content;
}


WordBody::WordBody()
{
}


WordBody::~WordBody()
{
}
