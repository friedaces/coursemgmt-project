#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Department.h"
#include "Interface.h"
#include "StudentInterface.h"
#include "AdminInterface.h"

using namespace std;

// Required Global Variables
Department* StoreDepartments = nullptr;
int TotalDepartments = 0;
const char* csvFile = "courses.csv";

void loadCSVData() {
    ifstream file(csvFile);
    if (!file.is_open()) return;

    file >> TotalDepartments;
    file.ignore(); // Clear newline

    if (TotalDepartments > 0) {
        StoreDepartments = new Department[TotalDepartments];
        for (int i = 0; i < TotalDepartments; ++i) {
            char line[256];
            file.getline(line, 256);

            // Parsing Department Name and Total Courses
            char* comma = strchr(line, ',');
            if (comma) {
                *comma = '\0';
                StoreDepartments[i].setDeptName(line);
                int courseCount = atoi(comma + 1);

                for (int j = 0; j < courseCount; ++j) {
                    char cNum[20], cName[100], sched[10];
                    double price;

                    file.getline(cNum, 20, ',');
                    file.getline(cName, 100, ',');
                    file.getline(sched, 10, ',');
                    file >> price;
                    file.ignore();

                    Course c(cNum, cName, sched, price);
                    StoreDepartments[i].addCourse(c);
                }
            }
        }
    }
    file.close();
}


int main() {
    loadCSVData();

    Interface* userInterface = nullptr;
    int choice = 0;

    cout << "====================================\n";
    cout << " Welcome to Course Management System\n";
    cout << "====================================\n";
    cout << "Student [1]" << endl << "Admin [2]" << endl << "Exit [3]" << endl;
    cout << "Enter your choice [1, 2, 3]: ";

    while (true) {
        if (cin >> choice && (choice >= 1 && choice <= 3)) {
            break;
        }
        cout << "Invalid input. Enter your choice [1, 2, 3]: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (choice == 1) {
        // Polymorphic usage of Interface pointer
        userInterface = new StudentInterface();
        userInterface->showMenu();
    }
    else if (choice == 2) {
        // Polymorphic usage of Interface pointer
        userInterface = new AdminInterface();
        userInterface->showMenu();
    }
    else {
        cout << "Exiting system. Goodbye!\n";
    }

    // Cleanup memory
    delete userInterface;
    delete[] StoreDepartments;

    return 0;
}
