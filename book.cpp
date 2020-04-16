#include <iostream>
#include <cstring>
#include "book.h"

using namespace std;

char* Book::getTitle() {
	return this->title;
}

char* Book::getName() {
	return this->name;
}

int Book::getYear() {
	return this->year;
}
bool Book::getImprumutat() {
	return this->imprumutat;
}

void Book::setTitle(const char* newTitle) {
	if (this->title) {
		delete[] this->title;
	}
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
}

void Book::setName(const char* newName) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

void Book::setImprumutat(bool newImprumutat) {
	this->imprumutat = newImprumutat;
}

void Book::setYear(int newYear) {
	this->year = newYear;
}

Book::Book() {
	//default constructor
	this->title = NULL;
	this->name = NULL;
	this->year = 0;
	this->imprumutat = false;

}

Book::Book(const char* t, const char* n, int y, bool i) {

	this->title = new char[strlen(t) + 1];
	strcpy_s(this->title, strlen(t) + 1, t);

	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);

	this->year = y;

	this->imprumutat = i;
}


Book::Book(const Book& b) {

	this->title = new char[strlen(b.title) + 1];
	strcpy_s(title, strlen(b.title) + 1, b.title);

	this->name = new char[strlen(b.name) + 1];
	strcpy_s(this->name, strlen(b.name) + 1, b.name);

	this->year = b.year;

	this->imprumutat = b.imprumutat;
}


Book::~Book() {
	//deconstructor
	
	if (this->title != NULL){
		delete[] title;
		this->title = NULL;
	}
	if (name != NULL) {
		delete[] name;
		this->name = NULL;
	}
	this->year = 0;
	this->imprumutat = false;
}

bool Book::operator==(const Book& b) {
	return ((this->year == b.year) && (strcmp(this->title, b.title) == 0) && (strcmp(this->name, b.name) == 0) && (this->imprumutat==b.imprumutat));
}

Book& Book::operator=(const Book& b) {
	this->setYear(b.year);
	this->setTitle(b.title);
	this->setName(b.name);
	this->setImprumutat(b.imprumutat);
	return *this;

}

ostream& operator<<(ostream& os, const Book& b)
{
	os << b.title << " " << b.name << " " << b.year<< " "<<b.imprumutat;
	return os;
}

bool Book::operator<(const Book& b)
{
	return (this->year < b.year);
}