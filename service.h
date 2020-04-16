#pragma once
#include "repo.h"
#include "book.h"

class Service {
private:
	RepoSTL<Book> repo;
public:
	Service() {};
	Service(RepoSTL<Book> r) { this->repo = r; };
    ~Service() {};
    void addBook(char* author, char* title, int year, bool imp);
    void delBook(char* author);
    void updateBook(char* title1, char* title2, char* name2, int year2, bool imp);
    queue<Book>* getAll();
    int getSizeRepo();
};

