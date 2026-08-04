
#include "Department.h"

Department::Department() {
    deptName[0] = '\0';
    courses = nullptr;
    totalCourses = 0;
}

Department::Department(const char* name) {
    strncpy(deptName, name, 99);
    deptName[99] = '\0';
    courses = nullptr;
    totalCourses = 0;
}

Department::Department(const Department& other) {
    strcpy(this->deptName, other.deptName);
    this->totalCourses = other.totalCourses;
    if (totalCourses > 0) {
        this->courses = new Course[totalCourses];
        for (int i = 0; i < totalCourses; ++i) {
            this->courses[i] = other.courses[i];
        }
    }
    else {
        this->courses = nullptr;
    }
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        delete[] courses;
        strcpy(this->deptName, other.deptName);
        this->totalCourses = other.totalCourses;
        if (totalCourses > 0) {
            this->courses = new Course[totalCourses];
            for (int i = 0; i < totalCourses; ++i) {
                this->courses[i] = other.courses[i];
            }
        }
        else {
            this->courses = nullptr;
        }
    }
    return *this;
}

Department::~Department() {
    delete[] courses;
}

const char* Department::getDeptName() const { return deptName; }
int Department::getTotalCourses() const { return totalCourses; }
Course* Department::getCourses() const { return courses; }

void Department::setDeptName(const char* name) {
    strncpy(deptName, name, 99);
    deptName[99] = '\0';
}

void Department::addCourse(const Course& course) {
    Course* temp = new Course[totalCourses + 1];
    for (int i = 0; i < totalCourses; ++i) {
        temp[i] = courses[i];
    }
    temp[totalCourses] = course;
    delete[] courses;
    courses = temp;
    totalCourses++;
}

void Department::displayDepartment() const {
    std::cout << "Department: " << deptName << "\n";
}