#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "proyek.h"

#define firstM(L) L.firstM
#define nextM(P) P->nextM
#define infoM(P) P->infoM
#define project(P) P->project

using namespace std;

struct manager{
    string name;
    string gender;
    int age;
    int entry_year;
};
typedef struct manager infotypeManager;
typedef struct elemListManager *addressM;

struct elemListManager{
    infotypeManager infoM;
    addressM nextM;
    ListProject project;
};

struct ListManager{
    addressM firstM;
};

void createListManager(ListManager &L);
addressM newListManager(infotypeManager x);

//function insert
void insertFirstManager(ListManager &L, addressM P);
void insertLastManager(ListManager &L, addressM P);
void addManager(ListManager &L, addressM P);

//function delete
void deleteFirstManager(ListManager &L, addressM P);
void deleteLastManager(ListManager &L, addressM P);
void deleteAfterManager(ListManager &L, addressM prec, addressM P);
void deleteManager(ListManager &L, addressM P);

//Function Update
void updateManager(ListManager &L, string nama, string gender, int umur, int entry, addressM P);

//Function lain lain
addressM searchManager(ListManager L, string name);

// Procedure dan function untuk tampilan
void showAll(ListManager L);
void showOnly(ListManager L, addressM P);
void showManager(ListManager L);
void showOnlyManager(ListManager L, addressM P);
void mainMenu();
void headerMenu();
void subMenu();
void tableHeader();
#endif // MANAGER_H_INCLUDED
