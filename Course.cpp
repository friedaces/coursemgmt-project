#include "Course.h"

// Default constructor
Course::Course() {
    courseNumber = nullptr;
    courseName = nullptr;
    schedule = nullptr;
    price = 0.0;
}

// Constructor that initializes all course information
Course::Course(const char* cNum, const char* cName, const char* sch, double p) {
    courseNumber = new char[strlen(cNum) + 1];
    strcpy(courseNumber, cNum);

    courseName = new char[strlen(cName) + 1];
    strcpy(courseName, cName);

    schedule = new char[strlen(sch) + 1];
    strcpy(schedule, sch);

    price = p;
}
// Copy constructor (creates a deep copy of another Course object)
Course::Course(const Course& other) {
    if (other.courseNumber) {
        courseNumber = new char[strlen(other.courseNumber) + 1];
        strcpy(courseNumber, other.courseNumber);
    }
    else courseNumber = nullptr;

    if (other.courseName) {
        courseName = new char[strlen(other.courseName) + 1];
        strcpy(courseName, other.courseName);
    }
    else courseName = nullptr;

    if (other.schedule) {
        schedule = new char[strlen(other.schedule) + 1];
        strcpy(schedule, other.schedule);
    }
    else schedule = nullptr;

    price = other.price;
}
// Copy assignment operator
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        delete[] courseNumber;
        delete[] courseName;
        delete[] schedule;

        if (other.courseNumber) {
            courseNumber = new char[strlen(other.courseNumber) + 1];
            strcpy(courseNumber, other.courseNumber);
        }
        else courseNumber = nullptr;

        if (other.courseName) {
            courseName = new char[strlen(other.courseName) + 1];
            strcpy(courseName, other.courseName);
        }
        else courseName = nullptr;

        if (other.schedule) {
            schedule = new char[strlen(other.schedule) + 1];
            strcpy(schedule, other.schedule);
        }
        else schedule = nullptr;

        price = other.price;
    }
    return *this;
}
// Destructor
Course::~Course() {
    delete[] courseNumber;
    delete[] courseName;
    delete[] schedule;
}

//getters

const char* Course::getCourseNumber() const { return courseNumber ? courseNumber : ""; }
const char* Course::getCourseName() const { return courseName ? courseName : ""; }
const char* Course::getSchedule() const { return schedule ? schedule : ""; }
double Course::getPrice() const { return price; }

void Course::setCourseNumber(const char* cNum) {
    delete[] courseNumber;
    courseNumber = new char[strlen(cNum) + 1];
    strcpy(courseNumber, cNum);
}

//setters
void Course::setCourseName(const char* cName) {
    delete[] courseName;
    courseName = new char[strlen(cName) + 1];
    strcpy(courseName, cName);
}

void Course::setSchedule(const char* sched) {
    delete[] schedule;
    schedule = new char[strlen(sched) + 1];
    strcpy(schedule, sched);
}

void Course::setPrice(double p) { price = p; }

// Display the course information
void Course::displayCourse() const {
    cout << getCourseNumber() << " - " << getCourseName()
        << " | Sched: " << getSchedule()
        << " | Price: $" << price << endl;
}
