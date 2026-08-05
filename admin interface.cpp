#include "AdminInterface.h" 
#include "Department.h"
#include "Course.h"
#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

AdminInterface::AdminInterface() {}
AdminInterface::~AdminInterface() {}

void AdminInterface::showMenu() {
    int adminChoice = 0;
    bool running = true;

    cout << endl;
    cout << "Welcome, admin!" << endl;
    //presenting all the options and directing each input to the relevant function
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

        adminChoice = getValidIntInput(1, 5); // inherited from Interface base class

        if (adminChoice == 1) {
            listAllDepartments();
        }
        else if (adminChoice == 2) {
            addDepartment();
        }
        else if (adminChoice == 3) {
            addCourseToDepartment();
        }
        else if (adminChoice == 4) {
            saveChangesToCSV();
        }
        else if (adminChoice == 5) {
            running = false; 
            cout << "Exiting Admin Interface..." << endl;
        }
    }
}

//loop through and print all departments with their index plus one to properly number them
void AdminInterface::listAllDepartments() {
    for (int i = 0; i < TotalDepartments; i++) {
        cout << i + 1 << ". " << StoreDepartments[i].getDeptName() << endl; 
    }
    if (TotalDepartments == 0) {
        cout << "No departments at the moment. " << endl;
    }
}
//prompt user to enter department name
void AdminInterface::addDepartment() {
    string deptName;
    cout << "Enter department name: " << endl;
    cin.ignore(1000, '\n'); 
    getline(cin, deptName); 

    while (deptName.empty()) {
        cout << "Please enter a valid department name: ";
        cin.ignore(1000, '\n'); 
        getline(cin, deptName);
    }

    // making a new array one bigger than the current to add the new department to
    Department* newDepts = new Department[TotalDepartments + 1];
    // copying everything old over to the new array using deep copy assignment operator
    for (int i = 0; i < TotalDepartments; i++) {
        newDepts[i] = StoreDepartments[i];
    }
    // adding the new department in the last place of the array
    newDepts[TotalDepartments] = Department(deptName.c_str());

    delete[] StoreDepartments; //freeing the memory
    // swapping the pointer to point to the new array
    StoreDepartments = newDepts;

    TotalDepartments++;//increase the department count to match

    cout << "Department added successfully." << endl;
}

//show all departments and prompt user to add course to dept
void AdminInterface::addCourseToDepartment() {
    listAllDepartments();
    if (TotalDepartments == 0) {
        return;   
    }

    cout << "Enter department number [0 to go back]" << endl;
    int choice = getValidIntInput(0, TotalDepartments);

    if (choice == 0) {
        return;
    }

    string course_num;
    string course_name;
    string course_sch; //schedule
    double course_price;

    cout << "Enter the course number: ";
    cin >> course_num;

    cout << "Enter course Name: ";
    cin.ignore(1000, '\n');
    getline(cin, course_name);   

    cout << "Enter course schedule [M/W, T/R, or W/F]: ";
    cin >> course_sch;

    while (course_sch != "M/W" && course_sch != "T/R" && course_sch != "W/F") { 
        cout << "Please enter a valid course schedule [M/W, T/R, or W/F]: ";
        cin >> course_sch;
    } 

    cout << "Enter course price: ";
    cin >> course_price;

    Course newCourse(course_num.c_str(), course_name.c_str(), course_sch.c_str(), course_price); 

    StoreDepartments[choice - 1].addCourse(newCourse); 

    cout << "Course added successfully." << endl;
}

// SAVING TO CSV: writes all modifications (departments and courses) to the csv file
void AdminInterface::saveChangesToCSV() {
    ofstream outFile(csvFile); 

    outFile << TotalDepartments << endl; 
    for (int i = 0; i < TotalDepartments; i++) {
        Department& dept = StoreDepartments[i];
        outFile << dept.getDeptName() << "," << dept.getTotalCourses() << endl; 

        Course* deptCourses = dept.getCourses();
        for (int j = 0; j < dept.getTotalCourses(); j++) {
            outFile << deptCourses[j].getCourseNumber() << ","
                << deptCourses[j].getCourseName() << ","
                << deptCourses[j].getSchedule() << ","
                << deptCourses[j].getPrice() << endl;
        }
    }

    outFile.close();

    cout << "Changes saved successfully." << endl;
}
