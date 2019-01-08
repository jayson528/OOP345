// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 07/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string.h>
#include "CString.h"
#define _CTR_SECURE_NO_WARNINGS

int stored = 3;

namespace w1 {
	CString::CString(const char* string) : MAX{ stored }, str { nullptr } {
		if (string != '\0') {
			str = new char[MAX + 1];
			strncpy(str, string, MAX);
			str[MAX] = '\0';
		}
		else {
			str = new char[1];
			str[0] = '\0';
		}
	}

	void CString::display(std::ostream& os) const {
		os << str;
	}

	CString::~CString() {
		delete[] str;
	}
 
	std::ostream& operator << (std::ostream& os, const CString& cStr) {
		static int counter = 0;
		os << counter++ << ": ";
		cStr.display(os);
		return os;
	}
}