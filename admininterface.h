#pragma once
#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H
#include "Interface.h"

class AdminInterface : public Interface {
public:
    AdminInterface();
    ~AdminInterface();
    void showMenu() override;

private:
    void listAllDepartments();      // Option 1: List Departments
    void addDepartment();           // Option 2: Add Department
    void addCourseToDepartment();   // Option 3: Add Course to Department
    void saveChangesToCSV();        // Option 4: Save Changes to CSV
};
#endif
