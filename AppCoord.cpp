#include <iostream>

#include "book.h"
#include "test.h"
#include "service.h"
#include "UI.h"


using namespace std;

int main()
{
    test();
    //RepoSTL<Book> repoSTL;
    RepoSTL<Book> repoSTL("BookOut.txt");
    Service service(repoSTL);
    UI ui(service);
    ui.runUI();

    return 0;
}