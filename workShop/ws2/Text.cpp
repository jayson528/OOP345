// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion:09/19/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace w2 {

	Text::Text() : str { nullptr }, numberOfLines{ 0 }{
		// Set safe empty state with initializer list
	};

	Text::Text(const std::string file_) : numberOfLines{ 0 } {
		// Create fileStream Obj
		std::ifstream file(file_);
		
		// Create a string variable to temp hold the current line from the file
		std::string tempLine;

		// Create a temp array of strings to hold the entire file 
		std::string* tempFile;

		// Create a temp variable to hold the number of files in the file
		std::size_t lineCheck = 0;

		// Check to see if the file was found and opned successfully
		if (file.is_open()) {
			// If file is NOT at the end of file, copy each line and increment the variable to determine how many lines there are
			while (!file.eof()) {
				std::getline(file, tempLine);
				++lineCheck;
			}
			// Allocate the correct amount of memory for the array based on the number of lines
			tempFile = new std::string[lineCheck];
			// Reset file to the beggining so it can be read again
			file.seekg(0);
			// Copy every line into the newly created array
			for (std::size_t i = 0; i < lineCheck; ++i) {
				std::getline(file, tempFile[i]);
			}
			// Assign the temp array of string to the current obj
			this->str = tempFile;
			this->numberOfLines = lineCheck;
		}
	};

	// Copy Constructor
	Text::Text(const Text& text_) {
		*this = text_;
	};

	// Move Constructor
	Text::Text(Text&& text_) {
		numberOfLines = text_.numberOfLines;
		str = text_.str;
		text_.str = nullptr;
	};

	// Copy Assignment Operator
	Text& Text::operator = (const Text& text_) {
		if (this != &text_) {
			numberOfLines = text_.numberOfLines;
			delete[] str;
			str = new std::string[numberOfLines];
			for (int i = 0; i < numberOfLines; ++i) {
				str[i] = text_.str[i];
			}
		}
		return *this;
	};

	// Move Assignment Operator
	Text& Text::operator = (Text&& text_) {
		if (this != &text_) {
			numberOfLines = text_.numberOfLines;
			delete[] str;
			str = new std::string[numberOfLines];
			str = text_.str;
			text_.str = nullptr;
		}
		return *this;
	};

	// Destructor
	Text::~Text() {
		delete[] str;
		str = nullptr;
	};
	
	std::size_t Text::size() const {
		return numberOfLines;
	};
}