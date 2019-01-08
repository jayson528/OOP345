// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 07/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

namespace w1 {

	class CString {
		const int MAX;
		char* str;
	public:
		CString(const char*);
		void display(std::ostream&) const;
		~CString();
	};
	std::ostream& operator << (std::ostream&, const CString&);
}
#endif