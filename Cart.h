#pragma once
#ifndef CART_H
#define CART_H

#include "Course.h"

class Cart {
private:
    Course* courses;        // Dynamic array of selected courses
    char** schedules;       // Parallel array to hold selected schedules
    int totalCount;
    double totalCost;
    const double TAX_RATE = 0.13; // Must add the taxes

public:
    Cart();
    ~Cart(); //Destructors

    void addCourse(const Course& course, const char* selectedSchedule);
    void listCourses() const;
    void checkout();
    int getTotalCount() const;
    void clearCart();
};

#endif
