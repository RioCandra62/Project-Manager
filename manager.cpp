#include <iostream>
#include <iomanip>
#include <string>
#include "manager.h"
#include "proyek.h"

using namespace std;


//Function create
void createListManager(ListManager &L){
    firstM(L) = NULL;
}

addressM newListManager(infotypeManager x){
    addressM P = new elemListManager;
    infoM(P) = x;
    nextM(P) = NULL;
    createListProject(project(P));
    return P;
}

//function insert
void insertFirstManager(ListManager &L, addressM P){
    if(firstM(L) != NULL){
        nextM(P) = firstM(L);
        firstM(L) = P;
    }else {
        firstM(L) = P;
    }
}
void insertLastManager(ListManager &L, addressM P){
    if(firstM(L) != NULL){
        addressM q = firstM(L);
        while (nextM(q) != NULL){
            q = nextM(q);
        }
        nextM(q) = P;
    }else {
        firstM(L) = P;
    }
}
void deleteFirstManager(ListManager &L, addressM P){
    if (firstM(L) != NULL){
        P = firstM(L);
        firstM(L) = nextM(P);
        nextM(P) = NULL;
    }else {
        firstM(L) = NULL;
    }
}

//function delete
void deleteLastManager(ListManager &L, addressM P){
    if (firstM(L) != NULL){
        addressM q = firstM(L);
        while (nextM(q) != NULL){
            q = nextM(q);
        }
        nextM(q) = NULL;
    }else {
        firstM(L) = NULL;
    }
}
void deleteAfterManager(ListManager &L, addressM prec, addressM P){
    nextM(prec) = nextM(P);
    nextM(P) = NULL;
}
void deleteManager(ListManager &L, addressM P){
    addressM q = firstM(L);
    while (nextM(q) != NULL){
        q = nextM(q);
    }
    if(P == firstM(L)){
        deleteFirstManager(L, P);
    }else if (P == q){
        deleteLastManager(L, P);
    }else {
        addressM precM = firstM(L);
        while (nextM(precM) != P){
            precM = nextM(precM);
        }
        deleteAfterManager(L, precM, P);
    }
}
//function Update

void updateManager(ListManager &L, string nama, string gender, int umur, int entry, addressM P){
    infoM(P).name = nama;
    infoM(P).gender = gender;
    infoM(P).age = umur;
    infoM(P).entry_year = entry;
}
//function lain lain
addressM searchManager(ListManager L, string name){
    addressM P = firstM(L);
    while(P != NULL){
        if (infoM(P).name == name){
            return P;
        }else {
            P = nextM(P);
        }
    }
    return NULL;
}
void showOnly(ListManager L, addressM P){
    int no = 1;
    if (firstM(L) != NULL){
            cout << "|" << setw(5) << left << no++;
            cout << setw(7) << "|" << setw(12) << left << infoM(P).name;
            cout << setw(4) << "|" << setw(7) << infoM(P).gender;
            cout << setw(6) << "|" << setw(6) << infoM(P).age;
            cout << setw(7) << "|" << setw(10) << infoM(P).entry_year;
            int numProject = numberOfProject(project(P));
            if (numProject > 0 ){
                cout << setw(7)<< "|" << setw(1) << numProject << " Project" << setw(7) << right << "|" << endl;
            }else {
                cout << setw(2) << "|" << "No Project assigned" << setw(2)<< right << "|"<< endl;
            }
            cout << "+-----+------------------+----------+-----------+----------------+---------------------+" << endl;
    }else {
        cout << "List is Empty" << endl;
    }
}

void showOnlyManager(ListManager L, addressM P){
    if(firstM(L) != NULL){
        cout << "---------------------------------" << endl;
        cout << "Manager Name : " << infoM(P).name << endl;
        cout << "Manager Gender : " << infoM(P).gender << endl;
        cout << "Manager Age : " << infoM(P).age << endl;
        cout << "Manager Entry Year : " << infoM(P).entry_year << endl;
        cout << "---------------------------------" << endl;
    }else {
        cout << "List is empty" << endl;
    }
}


//function show
void showManager(ListManager L){
    int no = 1;
    if (firstM(L) != NULL){
        addressM P = firstM(L);
        while(P != NULL){
            cout << "|" << setw(5) << left << no++;
            cout << setw(7) << "|" << setw(12) << left << infoM(P).name;
            cout << setw(4) << "|" << setw(7) << infoM(P).gender;
            cout << setw(6) << "|" << setw(6) << infoM(P).age;
            cout << setw(7) << "|" << setw(10) << infoM(P).entry_year;
            int numProject = numberOfProject(project(P));
            if (numProject > 0 ){
                cout << setw(7)<< "|" << setw(1) << numProject << " Project" << setw(7) << right << "|" << endl;
            }else {
                cout << setw(2) << "|" << "No Project assigned" << setw(2)<< right << "|"<< endl;
            }
            cout << "+-----+------------------+----------+-----------+----------------+---------------------+" << endl;
            P =  nextM(P);
        }
    }else {
        cout << "List is Empty" << endl;
    }
}

void showAll(ListManager L){
    if (firstM(L) != NULL){
        addressM P = firstM(L);
        while(P != NULL){
            tableHeader();
            showOnly(L, P);
            tableHeaderProject();
            showProject(project(P));
            P =  nextM(P);
        }
    }else {
        cout << "List is Empty" << endl;
    }
}

void headerMenu(){
    cout << "---------------------------------" << endl;
    cout << "       Project Manager data      " << endl;
    cout << "---------------------------------" << endl;
}

void mainMenu(){
    cout << "---------------------------------" << endl;
    cout << "       Project Manager Menu      " << endl;
    cout << "---------------------------------" << endl;
    cout << "Option :                         " << endl;
    cout << "1. Data Project Manager          " << endl;
    cout << "2. Add Project Manager           " << endl;
    cout << "3. Update Project Manager        " << endl;
    cout << "4. Delete Project Manager        " << endl;
    cout << "5. Project Menu                  " << endl;
    cout << "0. Exit                          " << endl;
    cout << "---------------------------------" << endl;
}

void subMenu(){
    cout << "---------------------------------" << endl;
    cout << "            Update Menu          " << endl;
    cout << "---------------------------------" << endl;
    cout << "Option :                         " << endl;
    cout << "1. Update Manager Name           " << endl;
    cout << "2. Update Manager Gender         " << endl;
    cout << "3. Update Manager Age            " << endl;
    cout << "4. Update Manager Entry Year     " << endl;
    cout << "5. Update All Manager Data       " << endl;
    cout << "0. Exit                          " << endl;
}


void tableHeader(){
    cout << "+=====+==================+==========+===========+================+=====================+" << endl;
    cout << "| No  |   Manager Name   |    Age   |   gender  |   Entry Year   |  Number of Project  |" << endl;
    cout << "+-----+------------------+----------+-----------+----------------+---------------------+" << endl;
}






















