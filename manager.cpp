#include <iostream>

#include "manager.h"
#include "proyek.h"

using namespace std;

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
    if(firstM(L) != NULL){
        cout << "Manager Name : " << infoM(P).name << endl;
        cout << "Manager Gender : " << infoM(P).gender << endl;
        cout << "Manager Age : " << infoM(P).age << endl;
        cout << "Manager Entry Year : " << infoM(P).entry_year << endl;
        cout << "---------------------------------" << endl;
        projectHeader();
        showProject(project(P));
    }else {
        cout << "List is empty" << endl;
    }
}



void showManager(ListManager L){

    if (firstM(L) != NULL){
        addressM P = firstM(L);
        while(P != NULL){
            cout << "Manager Name : " << infoM(P).name << endl;
            cout << "Manager Gender : " << infoM(P).gender << endl;
            cout << "Manager Age : " << infoM(P).age << endl;
            cout << "Manager Entry Year : " << infoM(P).entry_year << endl;
            int numProject = numberOfProject(project(P));
            if (numProject > 0 ){
                cout << "Number of Project : " << numProject << " Project" << endl;
            }else {
                cout << "Number of Project : No Project assigned" << endl;
            }
            cout << "---------------------------------" << endl;
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
            headerMenu();
            cout << "Manager Name : " << infoM(P).name << endl;
            cout << "Manager Gender : " << infoM(P).gender << endl;
            cout << "Manager Age : " << infoM(P).age << endl;
            cout << "Manager Entry Year : " << infoM(P).entry_year << endl;
            cout << "---------------------------------" << endl;\

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
    cout << "0. Exit                          " << endl;
    cout << "---------------------------------" << endl;
}























