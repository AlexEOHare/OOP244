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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Book.h"
#include <cstring>
using namespace std;

namespace sict {
	void Book::set(const char* fn,const char* ln,const char* title, long long isbn) {
		long long firstSum = 0;
		long long secondSum = 0;
		long long diff = 0;
		long long sum = 0;
		long long rounded = 0;
		long long checkDig = (isbn % 10);

		
		

			if (isbn < min_isbn_value || isbn > max_isbn_value) {
				m_isbn = 0;
				m_author_first[0] = '\0';
				m_author_last[0] = '\0';
				m_title[0] = '\0';
			}
			else {
				firstSum = (isbn / 1000000000000) + ((isbn / 10000000000) % 10) + ((isbn / 100000000) % 10) + ((isbn / 1000000) % 10) + ((isbn / 10000) % 10) + ((isbn / 100) % 10);
				secondSum = ((((isbn / 100000000000) % 10) + ((isbn / 1000000000) % 10) + ((isbn / 10000000) % 10) + ((isbn / 100000) % 10) + ((isbn / 1000) % 10) + ((isbn / 10) % 10))*3);
				sum = firstSum + secondSum;
				if ((sum % 10) != 0) {
					rounded = ((sum / 10) + 1) * 10;
				}
				diff = rounded - sum;

				if (diff == checkDig) {
					strncpy(m_author_first, fn, max_name_size);
					strncpy(m_author_last, ln, max_name_size);
					strncpy(m_title, title, max_title_size);
					m_isbn = isbn;
				}
				else {
					m_isbn = 0;
					m_author_first[0] = '\0';
					m_author_last[0] = '\0';
					m_title[0] = '\0';
				}
			
		}
	}
	bool Book::isEmpty() const {
		return !m_isbn;
	}
	void Book::display(bool m) const {
		if (!isEmpty() && !m) {
			cout << "Author: " << m_author_last << ", " << m_author_first << endl;
			cout << "Title: " << m_title << endl;
			cout << "ISBN-13: " << m_isbn << endl;
			cout << "Publication Year: " << m_year << endl;
			cout << "Price: " << m_price << endl;
		}
		else if (!isEmpty() && m) {
			cout.setf(ios::left);
			cout << "|";
			cout.setf(ios::right);
			cout.width(max_name_size);
			cout << m_author_last;
			cout.setf(ios::left);
			cout << "|";
			cout.width(max_name_size);
			cout << m_author_first;
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << "|";
			cout.width(max_title_size);
			cout << m_title;
			cout.setf(ios::left);
			cout << "|";
			cout.setf(ios::right);
			cout.width(13);
			cout << m_isbn;
			cout.setf(ios::left);
			cout << "|";
			cout.width(4);
			cout << m_year;
			cout.setf(ios::left);
			cout << "|";
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.width(6);
			cout.precision(2);
			cout << m_price;
			cout.setf(ios::right);
			cout << "|" << endl;
			cout.unsetf(ios::fixed);
			cout.unsetf(ios::right);
		}
		else if (isEmpty() && m) {
			cout.setf(ios::left);
			cout << "|";
			cout.width(92);
			cout << "The book object is empty!";
			cout << "|" << endl;

		}
		else {
			cout << "The book object is empty!" << endl;
		}
	}

	void Book::set(int year, double price) {
		if (!isEmpty()) {
			m_year = year;
			m_price = price;
		}
	}
}