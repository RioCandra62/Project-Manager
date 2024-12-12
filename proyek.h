#ifndef PROYEK_H_INCLUDED
#define PROYEK_H_INCLUDED

using namespace std;


#define firstC(L) L.firstC
#define lastC(L) L.lastC
#define nextC(P) P->nextC
#define prevC(P) P->prevC
#define infoC(P) P->infoC

struct proyek{
    string nama_proyek;
    int durasi_proyek;
    int nilai_proyek;
};
typedef struct proyek infotypeProject;
typedef struct elemListProject *addressP;

struct elemListProject{
    addressP nextC;
    addressP prevC;
    infotypeProject infoC;
};

struct ListProject{
    addressP firstC;
    addressP lastC;
};

void createListProject(ListProject &Lp);
addressP newListProject(infotypeProject x);

//Function Insert
void insertFirstProject(ListProject &Lp, addressP P);
void insertLastProject(ListProject &Lp, addressP P);


//function delete
void deleteFirstProject(ListProject &Lp, addressP P);
void deletelastProject(ListProject &Lp, addressP P);
void deleteAfterProject(ListProject &Lp, addressP prec, addressP P);
void deleteProject(ListProject &Lp, addressP P);

int numberOfProject(ListProject Lp);

//Function lain lain
addressP searchProject(ListProject Lp, string name);

//Function & procedure for GUI
void projectHeader();
void showProject(ListProject Lp);
void showProjectOnly(ListProject Lp, string projName);
void projectMenu();
void projectMenuHeader();

#endif // PROYEK_H_INCLUDED
