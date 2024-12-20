#include <iostream>
#include "manager.h"
#include "proyek.h"

using namespace std;

int main()
{
    ListManager L;
    int select, projNum, lastId, age, entry, oldAge;
    string projName, insertMethode, name, gender, oldName, oldEntry;
    infotypeManager input;
    infotypeProject inputProyek, data;
    addressM x, findM;
    addressP y, findProject;


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
    inputProyek.nama_proyek = "House";
    inputProyek.durasi_proyek = 63;
    inputProyek.nilai_proyek = 150;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    findM = searchManager(L, "John");
    inputProyek.id_proyek = 3;
    inputProyek.nama_proyek = "2 floor house";
    inputProyek.durasi_proyek = 428;
    inputProyek.nilai_proyek = 150;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    findM = searchManager(L, "John");
    inputProyek.id_proyek = 4;
    inputProyek.nama_proyek = "Pool";
    inputProyek.durasi_proyek = 63;
    inputProyek.nilai_proyek = 150;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);

    findM = searchManager(L, "Emily");
    inputProyek.id_proyek = 1;
    inputProyek.nama_proyek = "Garden";
    inputProyek.durasi_proyek = 365;
    inputProyek.nilai_proyek = 1200;
    y = newListProject(inputProyek);
    insertLastProject(project(findM), y);


    mainMenu();
    cout << "Enter your Option : ";
    cin >> select;
    while (select != 0){
        switch(select){
        case 1:
            cout << endl;
            tableHeader();
            showManager(L);
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
            cout << "Input Manager Name to Update : ";
            cin >> name;
            findM = searchManager(L, name);
            showOnlyManager(L, findM);
            subMenu();
            cout << "Select Your Option : ";
            cin >> select;
            oldName = infoM(findM).name;
            while(select != 0){
                switch (select){
                case 1:
                    cout << "Input New Manager Name : ";
                    cin >> name;
                    updateManager(L, name, infoM(findM).gender, infoM(findM).age, infoM(findM).entry_year, findM);
                    cout << "Manager name " << oldName << " changed to " << name << endl;
                    break;
                case 2:
                    cout << "Input New Manager Gender : ";
                    cin >> gender;
                    updateManager(L, infoM(findM).name, gender, infoM(findM).age, infoM(findM).entry_year, findM);
                    cout << "Manager Gender Updated"<< endl;
                    break;
                case 3:
                    oldAge = infoM(findM).age;
                    cout << "Input New Manager Age : ";
                    cin >> age;
                    updateManager(L, infoM(findM).name, infoM(findM).gender, age, infoM(findM).entry_year, findM);
                    cout << "Manager age Updated from " << oldAge << " to " << age << endl;
                    break;
                case 4:
                    oldEntry = infoM(findM).entry_year;
                    cout << "Input New Manager Entry Year : ";
                    cin >> entry;
                    updateManager(L, infoM(findM).name, infoM(findM).gender, age, entry, findM);
                    cout << "Manager Entry Year Updated from " << oldEntry << " to " << entry << endl;
                    break;
                case 5:
                    cout << "Input New Name : ";
                    cin >> name;
                    cout << "Input New Gender : ";
                    cin >> gender;
                    cout << "Enter New age : ";
                    cin >> age;
                    cout << "Enter New Entry Year : ";
                    cin >> entry;
                    updateManager(L, name, gender, age, entry, findM);
                    cout << "All Data Manager " << oldName << " has been Updated to " << name << " !" << endl;
                    break;
                default:
                    cout << "Your input is invalid !" << endl;
                }
                cout << endl;
                subMenu();
                cout << "Select Your Option : ";
                cin >> select;
            }
            break;
        case 4:
            cout << "Input Manager Name To Delete : ";
            cin >> name;
            findM = searchManager(L, name);
            deleteManager(L, findM);
            cout << "Data Deleted" << endl;
            break;
        case 5:
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
                        cout << "Input Manager Name : ";
                        cin >> name;
                        findM = searchManager(L, name);
                        showOnly(L, findM);
                        cout << "Input Project Number to Update : ";
                        cin >> projNum;
                        findProject = searchProjectNumber(project(findM), projNum);
                        data = infoC(findProject);
                        subMenuUpdateProyek();
                        cout << "Select Your Option : ";
                        cin >> select;
                        while (select != 0){
                            switch(select){
                            case 1:
                                cout << "Input New Project ID : ";
                                cin >> data.id_proyek;
                                updateProject(project(findM), findProject, data);
                                cout << "Project ID Updated!" << endl;
                                break;
                            case 2:
                                cout << "Input New Project Name : ";
                                cin >> data.nama_proyek;
                                updateProject(project(findM), findProject, data);
                                cout << "Project Name Updated!" << endl;
                            case 3:
                                cout << "Input New Duration : ";
                                cin >> data.durasi_proyek;
                                updateProject(project(findM), findProject, data);
                                cout << "Project Duration Updated!" << endl;
                            case 4:
                                cout << "Input New Project Value : ";
                                cin >> data.nilai_proyek;
                                updateProject(project(findM), findProject, data);
                                cout << "Project Value Updated" << endl;
                            case 5:
                                cout << "Input New Project ID : ";
                                cin >> data.id_proyek;
                                cout << "Input New Project Name : ";
                                cin >> data.nama_proyek;
                                cout << "Input New Duration : ";
                                cin >> data.durasi_proyek;
                                cout << "Input New Project Value : ";
                                cin >> data.nilai_proyek;
                                updateProject(project(findM), findProject, data);
                                cout << "Project Data Updated!" << endl;
                            }
                            subMenuUpdateProyek();
                            cout << "Select Your Option : ";
                            cin >> select;
                        }
                        break;
                    case 5:
                        cout << "Input Manager Name : ";
                        cin >> name;
                        findM = searchManager(L, name);
                        cout << "---------------------------------" << endl;
                        showProject(project(findM));
                        cout << "Input Project Number to delete : ";
                        cin >> projNum;
                        findProject = searchProjectNumber(project(findM), projNum);
                        deleteProject(project(findM), findProject);
                        cout << infoC(findProject).nama_proyek << " Has successfully deleted ! " << endl;
                        break;
                    default:
                        cout << "Your input is invalid!";
                    }
                    projectMenu();
                    cout << "Enter Your Option : ";
                    cin >> selectProject;
                    }
            break;
        default :
            cout << "Your input is Invalid!"<< endl;
        }
        cout << endl;
        mainMenu();
        cout << "Enter your input : ";
        cin >> select;
    }
    cout << "Exit, bye :)";
    return 0;
}
