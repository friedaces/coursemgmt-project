
#include <iostream>
#include <fstream>
#include <cstring>
#include "Department.h"
#include "Interface.h"
#include "StudentInterface.h"

using namespace std;

// Required Global Variables
Department* StoreDepartments = nullptr;
int TotalDepartments = 0;
const char* csvFile = "courses.csv";

void loadCSVData() {
    std::ifstream file(csvFile);
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
                    char cName[100], sched[10], cNum[20];
                    double price;

                    // Dummy reading logic for demo CSV structure
                    file.getline(cName, 100, ',');
                    file.getline(sched, 10, ',');
                    file >> price;
                    file.ignore();

                    sprintf(cNum, "CS%d", j + 101); // Default course number
                    Course c(cNum, cName, sched, price);
                    StoreDepartments[i].addCourse(c);
                }
            }
        }
    }
    file.close();
}

void createMockData() {
    // Populate mock departments if CSV does not exist
    TotalDepartments = 2;
    StoreDepartments = new Department[TotalDepartments];

    StoreDepartments[0].setDeptName("Computer Science");
    StoreDepartments[0].addCourse(Course("CS101", "Intro to C++", "M/W", 450.00));
    StoreDepartments[0].addCourse(Course("CS210", "Data Structures", "T/R", 500.00));

    StoreDepartments[1].setDeptName("Mathematics");
    StoreDepartments[1].addCourse(Course("MATH101", "Calculus I", "W/F", 400.00));
}

int main() {
    loadCSVData();
    if (TotalDepartments == 0) {
        createMockData(); // Ensure testing data exists
    }

    Interface* userInterface = nullptr;
    int choice = 0;

    std::cout << "====================================\n";
    std::cout << " Welcome to Course Management System\n";
    std::cout << "====================================\n";
    std::cout << "1. Student\n";
    std::cout << "2. Admin\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice [1, 2, 3]: ";

    while (true) {
        if (std::cin >> choice && (choice >= 1 && choice <= 3)) {
            break;
        }
        std::cout << "Invalid input. Enter your choice [1, 2, 3]: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    if (choice == 1) {
        // Polymorphic usage of Interface pointer
        userInterface = new StudentInterface();
        userInterface->showMenu();
    }
    else if (choice == 2) {
        std::cout << "Admin Interface is not implemented in this demo.\n";
    }
    else {
        std::cout << "Exiting system. Goodbye!\n";
    }

    // Cleanup memory
    delete userInterface;
    delete[] StoreDepartments;

    return 0;
}