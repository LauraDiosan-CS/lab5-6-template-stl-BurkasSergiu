#pragma once
#include "service.h"
class UI {
private:
    Service service;
    char* read();
    void displayMenu();
    void uiAddBook();
    void uiShowAll();
    void uiUpdateByTitle();
    void uiDeleteByTitle();
    void Imprumutat();
    void Returnare();
public:
    UI();
    UI(Service& service);
    void runUI();
};