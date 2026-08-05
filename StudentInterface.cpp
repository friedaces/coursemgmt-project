
#include "StudentInterface.h"
#include "Department.h"
#include <iostream>

using namespace std;

// Access global variables from main.cpp
extern Department* StoreDepartments;
extern int TotalDepartments;

StudentInterface::StudentInterface() {}
StudentInterface::~StudentInterface() {} // destructor of the previous student interface

void StudentInterface::showMenu() {
    int choice = 0;
    while (choice != 3) {
        cout << "\n===============================\n";
        cout << "      STUDENT MAIN MENU        \n";
        cout << "===============================\n";
        cout << "1. Show Cart\n";
        cout << "2. Browse Departments\n";
        cout << "3. Exit\n";
        cout << "Enter your choice [1, 2, 3]: ";

        choice = getValidIntInput(1, 3);

        switch (choice) {
        case 1:
            showCartMenu();
            break; // intentional break to go back to main menu
        case 2:
            browseDepartmentsMenu();
            break;
        case 3:
            cout << "Exiting Student Interface...\n";
            break;
        }
    }
}

void StudentInterface::showCartMenu() {
    int choice = 0;
    while (choice != 3) {
        cout << "\n--- SHOW CART MENU ---\n";
        cout << "1. List Courses\n";
        cout << "2. Checkout\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice [1, 2, 3]: ";

        choice = getValidIntInput(1, 3);

        if (choice == 1) {
            cart.listCourses();
        }
        else if (choice == 2) {
            cart.checkout();
            break; // Checkout returns to the Student Main Menu
        }
    }
}

void StudentInterface::browseDepartmentsMenu() {
    int choice = 0;
    while (choice != 2) {
        cout << "\n--- BROWSE DEPARTMENTS ---\n";
        if (TotalDepartments == 0) {
            cout << "No departments available.\n";
            return;
        }

        cout << "Available Departments:\n";
        for (int i = 0; i < TotalDepartments; ++i) {
            cout << i + 1 << ". " << StoreDepartments[i].getDeptName() << "\n";
        }

        cout << "\n1. List Courses of a Department\n";
        cout << "2. Go Back to Main Menu\n";
        cout << "Enter your choice [1, 2]: ";

        choice = getValidIntInput(1, 2);

        if (choice == 1) {
            listCoursesOfDepartment();
        }
    }
}

void StudentInterface::listCoursesOfDepartment() {
    cout << "\nEnter department number [0 to go back]: ";
    int deptIndex = getValidIntInput(0, TotalDepartments);

    if (deptIndex == 0) return;

    // Convert to 0-based indexing
    Department& selectedDept = StoreDepartments[deptIndex - 1];

    if (selectedDept.getTotalCourses() == 0) {
        cout << "No courses available in this department.\n";
        return;
    }

    cout << "\nCourses in " << selectedDept.getDeptName() << ":\n";
    Course* deptCourses = selectedDept.getCourses();
    for (int i = 0; i < selectedDept.getTotalCourses(); ++i) {
        cout << i + 1 << ". ";
        deptCourses[i].displayCourse();
    }

    int choice = 0;
    while (choice != 2) {
        cout << "\n1. Add to Cart a Course\n";
        cout << "2. Go Back to Browse Departments Menu\n";
        cout << "Enter your choice [1, 2]: ";

        choice = getValidIntInput(1, 2);

        if (choice == 1) {
            cout << "Enter course number to buy [0 to go back]: ";
            int courseIndex = getValidIntInput(0, selectedDept.getTotalCourses());

            if (courseIndex != 0) {
                Course selectedCourse = deptCourses[courseIndex - 1];
                cart.addCourse(selectedCourse, selectedCourse.getSchedule());
                cout << "Course added to cart successfully.\n";
            }
        }
    }
}
