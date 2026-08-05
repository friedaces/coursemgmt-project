#pragma once
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"

class Department
{
private:
	char deptName[100];
	Course* courses;
	int totalCourses;

public:
//default constructor
	Department();
	Department(const char* name);
	Department(const Department& other); // Copy constructor
	Department& operator=(const Department& other); // Copy assignment operator
	~Department();

	//Getters
	const char* getDeptName() const;
	int getTotalCourses() const;
	Course* getCourses() const;

	//Setters
	void setDeptName(const char* name);
	void addCourse(const Course& course);
	void displayDepartment() const;
};

#endif#pragma once
