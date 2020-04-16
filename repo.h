#pragma once
#include "book.h"
#include <queue>
#include <fstream>
#include <cstring>

template <class T>
class RepoSTL {
private:
	queue<T>* books;
	char* fileNameOut;
public:
	RepoSTL() {
		this->books = new queue<T>();
		this->fileNameOut = NULL;
	}
	RepoSTL(RepoSTL<T>& repo) {
		this->books = repo.books;
		this->fileNameOut = repo.fileNameOut;
	}
	RepoSTL<T>& operator=(RepoSTL<T>& repo)
	{
		this->books = repo.books;
		this->fileNameOut = repo.fileNameOut;
		return *this;
	}
	
	RepoSTL(const char* fileNameOut) {
		this->books = new queue<T>();
		this->fileNameOut = new char[strlen(fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
		this->loadFromFile();
	}
	~RepoSTL() {
		while (this->books->size() != 0)
			this->books->pop();
		if (this->fileNameOut)
			delete[] this->fileNameOut;
		this->fileNameOut = NULL;
	}
	void addItem(T s) {
		this->books->push(s);
		this->saveToFile();
	}
	queue<T>* getAll() {
		return this->books;
	}
	int getSize() {
		return this->books->size();
	}
	void deleteItem(char* title) {
		queue<T>* elem = this->getAll();
		queue<T>* aux = new queue<T>();
		int ok = 0;
		for (int i = 0; i < elem->size(); i++)
		{
			if (strcmp(elem->front().getTitle(), title) != 0)
			{
				aux->push(elem->front());
				elem->pop();
			}
			else
			{
				elem->pop();
				while (aux->size() != 0)
				{
					elem->push(aux->front());
					aux->pop();
				}
				ok = 1;
				break;
			}
		}
		if (!ok)
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
		this->saveToFile();
	}
	void updateItem(char* title, T& p2) {
		queue<T>* elem = this->getAll();
		queue<T>* aux = new queue<T>();
		int ok = 0;
		for (int i = 0; i < elem->size(); i++)
			if (strcmp(elem->front().getTitle(), title) != 0)
			{
				aux->push(elem->front());
				elem->pop();
			}
			else
			{
				elem->front() = p2;
				while (aux->size() != 0)
				{
					elem->push(aux->front());
					aux->pop();
				}
				ok = 1;
				break;
			}
		if (!ok)
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
		this->saveToFile();
	}
	
	void loadFromFile() {
		if (this->fileNameOut != NULL)
		{
			ifstream f(this->fileNameOut);
			char* title = new char[20];
			char* author = new char[20];
			int year;
			bool imprumut;
			while (!f.eof())
			{
				f >> title >> author >> year >> imprumut;
				Book b;
				b = Book(title, author, year, imprumut);
				this->addItem(b);
			}
			delete[] author;
			delete[] title;
			f.close();
		}
	}
	void saveToFile() {
		if (this->fileNameOut != NULL)
		{
			queue<T> *elem = this->books;
			queue<T> *aux = new queue<T>();
			ofstream f(this->fileNameOut);
			for (int i = 0; i < elem->size(); i++)
			{
				f << elem->front() << endl;
				aux->push(elem->front());
				elem->pop();
			}
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
			f.close();
		}
	}

};
