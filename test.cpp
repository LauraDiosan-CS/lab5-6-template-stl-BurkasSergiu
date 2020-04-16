#include <iostream>
#include <cstring>
#include <assert.h>
#include "book.h"
#include "repo.h"
#include "service.h"
void test()
{

	//test book
	char* title1 = new char[10];
	strcpy_s(title1, 4, "Ion");

	char* name1 = new char[10];
	strcpy_s(name1, 9, "Rebreanu");


	Book b(title1, name1, 1920,false);

	assert(strcmp(b.getTitle(), title1) == 0);
	assert(b.getYear() == 1920);
	assert(strcmp(b.getName(), name1) == 0);

	b.setYear(650);
	assert(b.getYear() == 650);
	

	//test service

	RepoSTL<Book> repo;
	Service service(repo);
	
	char* title2 = new char[10];
	strcpy_s(title2, strlen("Ion") + 1, "Ion");
	char* nume2 = new char[10];
	strcpy_s(nume2, strlen("Rebreanu") + 1, "Rebreanu");
	service.addBook(title2, nume2, 66, false);
	queue<Book>* carti = service.getAll();
	assert(carti->size() == 1);
	char* newTitle2 = new char[10];
	strcpy_s(newTitle2, strlen("Padurea") + 1, "Padurea");
	service.updateBook(title2, newTitle2, nume2, 66, false);
	assert(strcmp((carti->front().getTitle()), newTitle2)==0);
	service.delBook(newTitle2);
	assert(carti->size() == 0);

	cout << "tests are working \n";

}