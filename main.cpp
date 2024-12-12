#include <iostream>
#include "manager.h"
#include "proyek.h"

using namespace std;

int main()
{
    ListManager L;
    int select, projNum, lastId;
    string projName;
    infotypeManager input;
    infotypeProject inputProyek;
    addressM x, findM;
    addressP y, findProject;
    string insertMethode, name;

    createListManager(L);
    //Set Data
    input.name = "John";
    input.gender = "Male";
    input.age = 45;
    input.entry_year = 2024;
    x = newListManager(input);
    insertFirstManager(L, x);

    input.name = "Emily";
    input.gender = "Female";
    input.age = 25;
    input.entry_year = 2024;
    x = newListManager(input);
    insertLastManager(L, x);

    //Insert Project Data

    findM = searchManager(L, "John");
    inputProyek.id_proyek = 1;
    inputProyek.nama_proyek = "Apartment";
    inputProyek.durasi_proyek = 1825;
    inputProyek.nilai_proyek = 2500;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    findM = searchManager(L, "John");
    inputProyek.id_proyek = 2;
    inputProyek.nama_proyek = "Interior_renovation";
    inputProyek.durasi_proyek = 63;
    inputProyek.nilai_proyek = 150;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    findM = searchManager(L, "Emily");
    inputProyek.id_proyek = 1;
    inputProyek.nama_proyek = "Civilian_House";
    inputProyek.durasi_proyek = 365;
    inputProyek.nilai_proyek = 1024;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    mainMenu();
    cout << "Enter your Option : ";
    cin >> select;
    while (select != 0){
        switch(select){
        case 1:
            headerMenu();
            showManager(L);
            projectMenu();
            int selectProject;
            cout << "Enter Your Option : ";
            cin >> selectProject;
            while (selectProject != 0){
                switch(selectProject){
                    case 1:
                        showAll(L);
                    break;
                    case 2:
                        cout << "Enter Manager Name : ";
                        cin >> name;
                        findM = searchManager(L, name);
                        showOnly(L, findM);
                    break;
                    case 3:
                        cout << "Enter Manager Name : ";
                        cin >> name;
                        findM = searchManager(L, name);
                        cout << "Enter Project Name : ";
                        cin >> inputProyek.nama_proyek;
                        cout << "Enter Project Duration (days) : ";
                        cin >> inputProyek.durasi_proyek;
                        cout << "Enter Project Value (million) : ";
                        cin >> inputProyek.nilai_proyek;
                        inputProyek.id_proyek = getLastId(project(findM)) + 1;
                        y = newListProject(inputProyek);
                        cout << "Insert first or last ? ";
                        cin >> insertMethode;
                        if (insertMethode == "first" || insertMethode == "First"){
                            insertFirstProject(project(findM), y);
                            cout << "insert " << insertMethode << " success" << endl;
                        }else{
                            insertLastProject(project(findM), y);
                            cout << "insert " << insertMethode << " success" << endl;
                        }
                    break;
                    case 4:
                        cout << "Under Construction" << endl;
                        break;
                    case 5:
                        cout << "Input Manager Name : ";
                        cin >> name;
                        findM = searchManager(L, name);
                        cout << "---------------------------------" << endl;
                        showProject(project(findM));
                        cout << "Input Project Number to delete : ";
                        cin >> name;
                        findProject = searchProject(project(findM), name);
                        deleteProject(project(findM), findProject);
                        cout << name << " Has successfully deleted ! " << endl;
                        break;
                    default:
                        cout << "Your input is invalid!";
                    }
                    projectMenu();
                    cout << "Enter Your Option : ";
                    cin >> selectProject;
                    }
            break;
        case 2:
            cout << "Input Name : ";
            cin >> input.name;
            cout << "Input Gender : ";
            cin >> input.gender;
            cout << "Enter age : ";
            cin >> input.age;
            cout << "Enter Entry Year : ";
            cin >> input.entry_year;

            x = newListManager(input);
            cout << "Insert first or last ?" << endl;
            cin >> insertMethode;
            if(insertMethode == "first"){
                insertFirstManager(L, x);
            }else if (insertMethode == "last"){
                insertLastManager(L, x);
            }else {
                cout << "Invalid Input";
            }
            break;
        case 3:
            cout << "Enter Manager Name : ";
            cin >> name;
            findM = searchManager(L, name);
            cout << getLastId(project(findM)) << endl;
            break;
        case 4:
            cout << "Input Manager Name To Delete : ";
            cin >> name;
            findM = searchManager(L, name);
            deleteManager(L, findM);
            cout << "Data Deleted" << endl;
            break;
        default :
            cout << "Your input is Invalid!"<< endl;
        }
        mainMenu();
        cout << "Enter your input : ";
        cin >> select;
    }
    cout << "Exit, bye :)";
    return 0;
}
