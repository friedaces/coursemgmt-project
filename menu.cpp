#include <iostream>
#include <string>
#include "admin.h"
using namespace std;

int main() {
    int choice;
    cout << "Welcome! Please choose a login option from the list below:" << endl;
    cout << "Student [1]" << endl << "Admin [2]" << endl << "Exit [3]" << endl;

    cout << "Enter your choice [1, 2, 3]: ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option [1, 2, 3]: ";
        cin >> choice;
    }


    if (choice == 2) {
        cout << endl;
        cout << "Welcome, admin!" << endl;
        int adminChoice;
        bool running = true;

        while (running) {
            cout << endl;
            cout << "Options: " << endl;
            cout << "List Departments [1]" << endl;
            cout << "Add Department [2]" << endl;
            cout << "Add Course to Department [3]" << endl;
            cout << "Save Changes to CSV [4]" << endl;
            cout << "Exit [5]" << endl;
            cout << endl; 
            cout << "Enter your choice [1, 2, 3, 4, 5]: ";
            cin >> adminChoice;

            while (cin.fail() || adminChoice < 1 || adminChoice > 5) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a valid option [1, 2, 3, 4, 5]: ";
                cin >> adminChoice;
            }

            if (adminChoice == 1) {
                listDepartments();
            }

            else if (adminChoice == 2) {
                addDepartments();
            }
            else if (adminChoice == 3) {
                addCourse();
            }
            else if (adminChoice == 4) {
                saveToCSV();
            }
            else if (adminChoice == 5) {
                running = false; // this is what stops the while loop
            }
        }
    }

    return 0;
}