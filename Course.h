#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>
using namespace std;

class Course
{
private:
	char* courseNumber;
	char* courseName;
	char* schedule;
	double price;
public:
	Course();
	Course(const char* cNum, const char* cName, const char* sch, double p);
	Course(const Course& other);
	Course& operator=(const Course& other);
	~Course();
	// Getters
	const char* getCourseNumber() const;
	const char* getCourseName() const;
	const char* getSchedule() const;
	double getPrice() const;
	// setters
	void setCourseNumber(const char* cNum);
	void setCourseName(const char* cName);
	void setSchedule(const char* sch);
	void setPrice(double p);
	void displayCourse() const;
};
#endif
