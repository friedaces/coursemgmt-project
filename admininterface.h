#pragma once
#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H
#include "Interface.h"

class AdminInterface : public Interface {
public:
    AdminInterface();
    ~AdminInterface();
    void showMenu() override; //tells the compiler it's intended to replace a virtual function from a base class

private:
    void listAllDepartments();      // Option 1: List Departments function
    void addDepartment();           // Option 2: Add Department function
    void addCourseToDepartment();   // Option 3: Add Course to Department function
    void saveChangesToCSV();        // Option 4: Save Changes to CSV function
};
#endif
