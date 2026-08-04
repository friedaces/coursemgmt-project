#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstring>

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
#endif
