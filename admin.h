#pragma once
#include <iostream>
#include <string>
using namespace std;

//CLASSES
//COURSES
class Courses {
private:
	int number;
	string name;
	string schedule;
	double price;
public:
	Courses(); // default constructor
	Courses(int n, string na, string sch, double p);

	void display() const;   // prints itself 
	void saveToFile(ofstream& outFile) const; //writes itself to the csv
};

//DEPARTMENTS
class Department {
private:
	string deptName;
	Courses* courseList;   // department's array of courses
	int courseCount;
public:
	Department();                          // default constructor
	Department(string name);               // constructor with name
	Department(const Department& other);   // copy constructor 
	Department& operator=(const Department& other); // assignment operator 
	~Department();                         // destructor

	void display(int index) const;   // display function that prints "index. deptName"
	void addCourse(Courses c);
	void listCourses() const;
	void saveToFile(ofstream& outFile) const;
};

extern int sizeDept;
extern Department* departments;

void listDepartments();
void addDepartments();
void addCourse();
void saveToCSV();