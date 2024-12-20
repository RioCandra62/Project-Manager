#ifndef PROYEK_H_INCLUDED
#define PROYEK_H_INCLUDED

using namespace std;


#define firstC(L) L.firstC
#define lastC(L) L.lastC
#define nextC(P) P->nextC
#define prevC(P) P->prevC
#define infoC(P) P->infoC

struct proyek{
    int id_proyek;
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
void deletelastProject(ListProject &Lp);
void deleteAfterProject(ListProject &Lp, addressP prec, addressP P);
void deleteProject(ListProject &Lp, addressP P);

//function Update
void updateProject(ListProject &Lp, addressP P, infotypeProject data);

//Function lain lain
addressP searchProject(ListProject Lp, string name);
addressP searchProjectNumber(ListProject Lp, int projNum);
int getLastId(ListProject Lp);
int numberOfProject(ListProject Lp);

//function tampilan
void projectHeader();
void showProject(ListProject Lp);
void showProjectOnly(ListProject Lp, string projName);
void projectMenu();
void projectMenuHeader();
void subMenuUpdateProyek();
void tableHeaderProject();
#endif // PROYEK_H_INCLUDED
