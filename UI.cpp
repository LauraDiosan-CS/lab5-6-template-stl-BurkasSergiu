#include "UI.h"
#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::displayMenu()
{
	cout << "1. Add a book" << endl;
	cout << "2. Modify a book" << endl;
	cout << "3. Delete a book" << endl;
	cout << "4. Show all books" << endl;
	cout << "5. Borrow a book" << endl;
	cout << "6. Return a book" <<endl;
	cout << "\nGive option: \n";
}

char* UI::read()
{
	char b[100];
	cin >> b;
	char* a = new char[strlen(b) + 1];
	strcpy_s(a, strlen(b) + 1, b);
	return a;
}

void UI::uiAddBook()
{
	cout << "Title: ";
	char* a = this->read();
	cout << "Author: ";
	char* b = this->read();
	cout << "Year: ";
	int year;
	cin >> year;
	this->service.addBook(a,b,year,false);
}

void UI::uiShowAll()
{
	queue<Book>* carti = service.getAll();
	queue<Book>* aux = new queue<Book>();
	while (carti->size() != 0)
	{
		cout << carti->front() << '\n';
		aux->push(carti->front());
		carti->pop();
	}
	while (aux->size() != 0)
	{
		carti->push(aux->front());
		aux->pop();
	}
}



void UI::uiUpdateByTitle()
{
	cout << "The title that you want modified: ";
	char* oldTitle = this->read();
	cout << "The new name of the title: ";
	char* newTitle = this->read();
	cout << "The new author: ";
	char* newName = this->read();
	cout << "Year: ";
	int newYear;
	cin >> newYear;

	this->service.updateBook(oldTitle,newTitle, newName, newYear, false);
}

void UI::uiDeleteByTitle()
{
	cout << "The title that you want deleted: ";
	char* title = this->read();
	this->service.delBook(title);
}

void UI::Imprumutat()
{
	cout << "Title: ";
	char* title = this->read();
	cout << "Author: ";
	char* name = this->read();
	queue<Book>* books = service.getAll();
	queue<Book>* aux = new queue<Book>();
	for (int i = 0; i < books->size(); i++)
	{
		if (strcmp(books->front().getName(), name) == 0 && strcmp(books->front().getTitle(), title) == 0)
		{
			if (books->front().getImprumutat() == false)
				books->front().setImprumutat(true);
			else
				cout << "The book was already borrowed \n";
			break;
		}
		aux->push(books->front());
		books->pop();
	}
	while (aux->size() != 0)
	{
		books->push(aux->front());
		aux->pop();
	}
}
void UI::Returnare()
{
	cout << "Title: ";
	char* title = this->read();
	cout << "Name: ";
	char* author = this->read();
	queue<Book>* carti = service.getAll();
	queue<Book>* aux = new queue<Book>();
	for (int i = 0; i < carti->size(); i++)
	{
		if (strcmp(carti->front().getName(), author) == 0 && strcmp(carti->front().getTitle(), title) == 0)
		{
			if (carti->front().getImprumutat() == true)
			{
				cout << "Book has been returned succesfully!" << '\n';
				carti->front().setImprumutat(false);
			}
			else
				cout << "Not borrowed yet!" << '\n';
			break;
		}
		aux->push(carti->front());
		carti->pop();
	}
	while (aux->size() != 0)
	{
		carti->push(aux->front());
		aux->pop();
	}

}

void UI::runUI()
{
	bool shouldRun = true;
	int cmd;
	while (shouldRun)
	{
		this->displayMenu();
		cin >> cmd;
		if (cmd==1)  //string::npos = -1
		{
			this->uiAddBook();
		}
		else if (cmd==2)
		{
			this->uiUpdateByTitle();
		}
		else if (cmd==3)
		{
			this->uiDeleteByTitle();
		}
		else if (cmd==4)
		{
			this->uiShowAll();
		}
		else if (cmd == 5)
		{
			this->Imprumutat();
		}
		else if (cmd == 6)
		{
			this->Returnare();
		}
		else
			shouldRun = false;
	}
}


