/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	w3_in_lab.cpp
// Version 1.0
// Date	2016/01/10
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Name            Date            Reason
// Alex O'Hare		31/01/2019				in_lab
// Alex O'Hare    04/02/2019				at_home
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict {
	// constant interget values
	const int max_title_size = 32;
	const int max_name_size = 16;

	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book {
		char m_author_last[max_name_size + 1];
		char m_author_first[max_name_size + 1];
		char m_title[max_title_size + 1];
		long long m_isbn;
		int m_year;
		double m_price;

	public:
		void set(const char* auth_last,const char* auth_first,const char* title, long long isbn);
		bool isEmpty() const;
		void display(bool multiple = false) const;
		void set(int year, double price);
	};
}


#endif