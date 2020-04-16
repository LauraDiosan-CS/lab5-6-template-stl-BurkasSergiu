#include "service.h"
#include "book.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

queue<Book>* Service::getAll() {
    return this->repo.getAll();
}
int Service::getSizeRepo() {
    return this->repo.getSize();
}

void Service::addBook(char* title, char* name, int year, bool imp) {
    Book b = Book(title, name, year, imp);
    this->repo.addItem(b);
}
void Service::delBook(char* title) {
    repo.deleteItem(title);
}
void Service::updateBook(char* title1, char* title2, char* name2, int year2, bool imp) {
    Book b = Book(title2,name2, year2, imp);
    this->repo.updateItem(title1, b);
}
