#include "StringifyableArray.h"

std::string StringifyableArray::stringify() {
	std::string s;
	for (auto entity : *content) {
		s += entity->stringify();
	}
	return s;
}


StringifyableArray StringifyableArray::add(Stringifyable* element) {
	this->content->push_back(element);
	return *this;
}


void StringifyableArray::clear() {
	this->content->clear();
}


StringifyableArray::StringifyableArray(std::vector <Stringifyable*>* content) {
	this->content = content;
}


StringifyableArray::StringifyableArray()
{
}


StringifyableArray::~StringifyableArray()
{
}
