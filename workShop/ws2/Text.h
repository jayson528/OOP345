// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion:09/19/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W2_TEXT_H
#define W2_TEXT_H

namespace w2 {

	class Text {
		std::string* str;
		int numberOfLines;
	public:
		Text();
		Text(const std::string);
		Text(const Text&);
		Text& operator = (const Text&);
		Text(Text&&);
		Text& operator = (Text&&);
		~Text();
		std::size_t size() const;
	};
};
#endif 


