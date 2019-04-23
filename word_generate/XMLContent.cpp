#include "XMLContent.h"


XMLContent::XMLContent(std::string content) {
	this->content = content;
}


XMLContent::XMLContent()
{
}


XMLContent::~XMLContent()
{
}


std::string XMLContent::stringify() {
	return this->content;
}