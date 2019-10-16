// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Yue Chen
// 2018.06.27
#include<iostream>
#include<fstream>
#include<string>
#include<new>
#include"Text.h"
using namespace sict;
Text::Text() { }
Text::Text(const std::string fileName) {
	std::string* tempText ;
	std::string tempStr;
	size_t counter = 0;

	std::ifstream fin(fileName);
	if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin,tempStr);
            counter++;
        }
        tempText = new std::string[counter];
        fin.seekg(0,fin.beg);
        for (int i = 0; i < counter + 1; i++) {
            getline(fin,tempText[i]);
        }
		this->strings = tempText;
		this->counter = counter;
	}
}
Text::Text(const Text& _text) {
	*this = _text;
}
Text& Text::operator=(const Text& _text) {
	if (this != &_text) {
		delete[] strings;
		strings = new std::string[_text.counter];
		for (size_t i = 0; i < _text.counter; i++)
			strings[i] = _text.strings[i];
		counter = _text.counter;
	}
	return *this;
}
Text::Text(Text&& _text) { *this = std::move(_text); }
Text&& Text::operator=(Text&& _text) {
	if (this != &_text) {
		delete[] strings;
		strings = new std::string[_text.counter];
		for (size_t i = 0; i < _text.counter; i++)
			strings[i] = _text.strings[i];
		counter = _text.counter;
	}
	_text.counter = 0;
	_text.strings = nullptr;
	return std::move(*this);
}
Text::~Text() {}
size_t Text::size() const {
	return counter;
}