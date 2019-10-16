// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Yue Chen
// 2018.06.27
#pragma once
namespace sict {
	class Text {
		std::string* strings;
		size_t counter;
	public:
		Text();
		Text(const std::string fileName);
		Text(const Text& _text);
		Text& operator=(const Text& _text);
		Text(Text&& _text);
		Text&& operator=(Text&& _text);
		~Text();
		size_t size() const;
	};
}
