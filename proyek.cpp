#include <iostream>
using namespace std;
#include "proyek.h"
#include "manager.h"
#include <iostream>
#include <iomanip>
#include <string>

void createListProject(ListProject &Lp){
    firstC(Lp) = NULL;
    lastC(Lp) = NULL;
}

addressP newListProject(infotypeProject x){
    addressP P = new elemListProject;
    infoC(P) = x;
    nextC(P) = NULL;
    prevC(P) = NULL;
    return P;
}

void insertFirstProject(ListProject &Lp, addressP P){
    if(firstC(Lp) == NULL){
        firstC(Lp) = P;
        lastC(Lp) = P;
    }else {
        nextC(P) = firstC(Lp);
        prevC(firstC(Lp)) = P;
        firstC(Lp) = P;
    }
}

void insertLastProject(ListProject &Lp, addressP P){
    if (firstC(Lp) != NULL){
        prevC(P) = lastC(Lp);
        nextC(lastC(Lp)) = P;
        lastC(Lp) = P;
    }else {
        firstC(Lp) = P;
        lastC(Lp) = P;
    }
}

int numberOfProject(ListProject Lp){
    int total = 0;
    addressP q = firstC(Lp);
    while (q != NULL){
        total++;
        q = nextC(q);
    }
    return total;
}

void deleteFirstProject(ListProject &Lp, addressP P){
    if(firstC(Lp) != NULL){
        P = firstC(Lp);
        firstC(Lp) = nextC(P);
        nextC(P) = NULL;
        prevC(firstC(Lp)) = NULL;
    }else {
        firstC(Lp) = NULL;
        lastC(Lp) = NULL;
    }
}

void deletelastProject(ListProject &Lp){
    addressP P = lastC(Lp);
    if(firstC(Lp) != NULL){
        if(firstC(Lp) != lastC(Lp)){
            lastC(Lp) = prevC(P);
            nextC(lastC(Lp)) = NULL;
        }else {
            firstC(Lp) = NULL;
            lastC(Lp) = NULL;
        }
    }else {
        cout << "List empty" << endl;
    }
}

void deleteAfterProject(ListProject &Lp, addressP prec, addressP P){
    P = nextC(prec);
    nextC(prec) = nextC(P);
    prevC(nextC(P)) = prec;
    prevC(P) = NULL;
    nextC(P) = NULL;
}

void deleteProject(ListProject &Lp, addressP P){
    if (P == firstC(Lp)){
        deleteFirstProject(Lp, P);
    }else if(P == lastC(Lp)){
        deletelastProject(Lp);
    }else {
        deleteAfterProject(Lp, prevC(P), P);
    }
}

void updateProject(ListProject &Lp, addressP P, infotypeProject data){
    infoC(P).durasi_proyek = data.durasi_proyek;
    infoC(P).nama_proyek = data.nama_proyek;
    infoC(P).nilai_proyek = data.nilai_proyek;
    infoC(P).durasi_proyek = data.durasi_proyek;
}


addressP searchProject(ListProject Lp, string projName){
    addressP P = firstC(Lp);
    while(P != NULL){
        if(infoC(P).nama_proyek == projName){
            return P;
        }else {
            P = nextC(P);
        }
    }
    return NULL;
}

addressP searchProjectNumber(ListProject Lp, int projNum){
    addressP P = firstC(Lp);
    while(P != NULL){
        if(infoC(P).id_proyek == projNum){
            return P;
        }else {
            P = nextC(P);
        }
    }
    return NULL;
}


 void showProject(ListProject Lp){
    addressP q = firstC(Lp);
    if (firstC(Lp) != NULL){
        while (q != NULL){
            cout << "|" << setw(5) <<  infoC(q).id_proyek;
            int year, month, day;
            int duration = infoC(q).durasi_proyek;
            int value = infoC(q).nilai_proyek;
            cout << "|" << setw(18) << left << infoC(q).nama_proyek;
            year = duration / 365;
            duration = duration % 365;
            month = duration / 30;
            duration = duration % 30;
            day = duration;
            if (year != NULL && month == NULL && day == NULL){
                if (year == 1){
                    cout << "|" << year << setw(29) << left << " Year";
                }else {
                    cout << "|" << year <<  setw(29) << left << " Years";
                }
            } else if (year != NULL){
                cout <<"|"<< year << " Years " << month << " Months and " << day << setw(8) << " Days";
            }else if(month != NULL && year == NULL && day == NULL){
                if (year == 1){
                    cout << "|" << month << " Month";
                }else {
                    cout << "|" << month << setw(5) << left << " Months";
                }
            }else if(year == NULL && month != NULL){
                cout << "|" << month << " Months and " << day << setw(16) << left << " Days";
            }else {
                if (day != 1){
                    cout << "|" << day << setw(13) << left << " days ";
                }else {
                    cout << "|" << day << setw(13) << left << " day ";
                }
            }
            if (value >= 1000){
                float finalValue;
                finalValue = (float)value / 1000;
                cout << "|" << finalValue << setw(15) << left <<" Billion" << "|" << endl;
            }else {
                cout << "|" << value << setw(15) << " Million" << "|" << endl;
            }
            cout << "+-----+------------------+------------------------------+------------------+" << endl;
            q = nextC(q);
        }
    }else {
        cout << "No Project Data" << endl;
    }
 }


 int totalProject(ListProject Lp){
    addressP q = firstC(Lp);
    int total = 0;
    while(q != NULL){
        total++;
        q = nextC(q);
    }
    return total;
 }

 int getLastId(ListProject Lp){
     addressP q = lastC(Lp);
     return infoC(q).id_proyek;
 }


 void projectHeader(){
    cout << "---------------------------------" << endl;
    cout << "           Data Project          " << endl;
    cout << "---------------------------------" << endl;
 }


void projectMenu(){
    cout << "---------------------------------" << endl;
    cout << "           Menu Project          " << endl;
    cout << "---------------------------------" << endl;
    cout << "Option :                         " << endl;
    cout << "1.All Project Data               " << endl;
    cout << "2.Find Project By Manager Name   " << endl;
    cout << "3.Add Project Data               " << endl;
    cout << "4.Edit Project Data              " << endl;
    cout << "5.Delete Project Data            " << endl;
    cout << "0.Exit                           " << endl;
    cout << "---------------------------------" << endl;
}
void subMenuUpdateProyek(){
    cout << "---------------------------------" << endl;
    cout << "            Update Menu          " << endl;
    cout << "---------------------------------" << endl;
    cout << "Option :                         " << endl;
    cout << "1. Update Project ID             " << endl;
    cout << "2. Update Project Name           " << endl;
    cout << "3. Update Project Duration       " << endl;
    cout << "4. Update Project Value          " << endl;
    cout << "5. Update All Project Data       " << endl;
    cout << "0. Exit                          " << endl;
}

void tableHeaderProject(){
    cout << "+=====+==================+==============================+==================+" << endl;
    cout << "| ID  |   Project Name   |       Project Duration       |   Project Value  |" << endl;
    cout << "+-----+------------------+------------------------------+------------------+" << endl;
}




