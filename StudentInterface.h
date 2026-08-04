#pragma once
#ifndef STUDENTINTERFACE_H
#define STUDENTINTERFACE_H

#include "Interface.h"
#include "Cart.h"

class StudentInterface : public Interface {
private:
    Cart cart;

    void showCartMenu();
    void browseDepartmentsMenu();
    void listCoursesOfDepartment();

public:
    StudentInterface();
    ~StudentInterface();

    void showMenu() override; // Polymorphic entry point
};

#endif
