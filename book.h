#pragma once


#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Book {
private:
	char* title;
	char* name;
	int year;
	bool imprumutat;

public:
	char* getTitle();
	char* getName();
	int getYear();
	bool getImprumutat();

	void setTitle(const char* newTitle);
	void setName(const char* newName);
	void setYear(int newYear);
	void setImprumutat(bool newImprumutat);

	Book();

	Book(const char* t, const char* n, int y,bool i);

	Book(const Book& p);

	~Book();   //deconstructor !!!!!!!!!!

	bool operator==(const Book& b);

	Book& operator=(const Book& b);

	bool operator<(const Book& b);

	friend ostream& operator<<(ostream& os, const Book& b);
};
#endif
