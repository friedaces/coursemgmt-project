#include <iostream>
#include <string>
#include "admin.h"
#include <fstream> //for csv
using namespace std;

int sizeDept = 0;
Department* departments = new Department[0];

//COURSES CLASS
Courses::Courses() {
	number = 0;
	schedule = "";
	price = 0.0;
}

Courses::Courses(int n, string na, string sch, double p) {
	number = n;
	name = na;
	schedule = sch;
	price = p;
}

void Courses::display() const {
	cout << number << " - " << name << " | " << schedule << " | $" << price << endl;
} //how the course will be displayed

//DEPARTMENT CLASS

Department::Department() {
	deptName = "";
	courseList = new Courses[0];
	courseCount = 0;
}

Department::Department(string name) {
	deptName = name;
	courseList = new Courses[0];
	courseCount = 0;
}

//======================================

//making a deep copy constructor so when copying a department, u copy
//the actual courselist array

Department::Department(const Department& other) {
	deptName = other.deptName;
	courseCount = other.courseCount;
	courseList = new Courses[courseCount];
	for (int i = 0; i < courseCount; i++) {
		courseList[i] = other.courseList[i];
	}
}

//======================================

//assignment operator so we can equate department a = b

Department& Department::operator=(const Department& other) {
	if (this == &other) return *this;   // guard against self-assignment

	delete[] courseList;                // free what this object currently holds

	deptName = other.deptName;
	courseCount = other.courseCount;
	courseList = new Courses[courseCount];
	for (int i = 0; i < courseCount; i++) {
		courseList[i] = other.courseList[i];
	}
	return *this;
}

Department::~Department() { //destructor
	delete[] courseList;
}

void Department::display(int index) const {
	cout << index << ". " << deptName << endl; //how departments will be displayed
}

void Department::addCourse(Courses c) { //adding a course to dept.
	Courses* newCourses = new Courses[courseCount + 1];
	for (int i = 0; i < courseCount; i++) {
		newCourses[i] = courseList[i];
	}
	newCourses[courseCount] = c;
	delete[] courseList;
	courseList = newCourses;
	courseCount++;
}

void Department::listCourses() const {
	if (courseCount == 0) {
		cout << "No courses in this department yet." << endl;
		return;
	}
	for (int i = 0; i < courseCount; i++) {
		cout << i + 1 << ". ";
		courseList[i].display();
	}
}

//===========================================


void listDepartments() {
	for (int i = 0; i < sizeDept; i++) {
		departments[i].display(i + 1);
	}
	if (sizeDept == 0) {
		cout << "No departments at the moment. " << endl;
	}
}

void addDepartments() {
	string deptName;
	cout << "Enter department name: " << endl;
	cin.ignore(1000, '\n');
	getline(cin, deptName);

	while (deptName.empty()) {
		cout << "Please enter a valid department name: ";
		cin.ignore(1000, '\n');
		getline(cin, deptName);
	}

//making a new array one bigger than the current
	Department* newDepts = new Department[sizeDept + 1];
//copying everything old over
	for (int i = 0; i < sizeDept; i++) {
		newDepts[i] = departments[i];
	}
//adding the new department in the last place of the array
	newDepts[sizeDept] = Department(deptName);

	delete[] departments;
	//swapping the pointer to point to the new array
	departments = newDepts;

	sizeDept++;
	
	cout << "Department added successfully." << endl;
}

void addCourse() {
	listDepartments();
	if (sizeDept == 0) {
		return;   // if there are no departments to add a course to, return
	}

	int choice;
	cout << "Enter department number [0 to go back]" << endl;
	cin >> choice;

	while (cin.fail() || choice < 0 || choice > sizeDept) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid department number: ";
		cin >> choice;
	}

	if (choice == 0) {
		return;
	}

	int course_num;
	string course_name;
	string course_sch;
	double course_price;

	cout << "Enter the course number: ";
	cin >> course_num;

	cout << "Enter course Name: ";
	cin.ignore(1000, '\n');       
	getline(cin, course_name);   // getline so multiple word names work

	cout << "Enter course schedule [M/W, T/R, or W/F]: ";
	cin >> course_sch;

	while (course_sch != "M/W" && course_sch != "T/R" && course_sch != "W/F") {
		cout << "Please enter a valid course schedule [M/W, T/R, or W/F]: ";
		cin >> course_sch;
	} //checking the input is valid

	cout << "Enter course price: ";
	cin >> course_price;

	Courses newCourse(course_num, course_name, course_sch, course_price);

	departments[choice - 1].addCourse(newCourse); //-1 to get the actual index

	cout << "Course added successfully." << endl;

}

// saving courses to csv
void Courses::saveToFile(ofstream& outFile) const {
	outFile << number << "," << name << "," << schedule << "," << price << endl;
}

//saving departments to csv
void Department::saveToFile(ofstream& outFile) const {
	outFile << deptName << "," << courseList << "," << courseCount << endl;
}
//SAVING TO CSV: writes all modifications (departments and courses) to the csv file
void saveToCSV() {

	ofstream outFile("dept_and_coureses.csv");


	for (int i = 0; i < sizeDept; i++) {
		departments[i].saveToFile(outFile);
	}

	outFile.close();

	cout << "Changes saved successfully.";
	return;
}

