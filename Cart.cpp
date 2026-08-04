
#include "Cart.h"

using namespace std;

Cart::Cart() {
    courses = nullptr;
    schedules = nullptr;
    totalCount = 0;
    totalCost = 0.0;
}

Cart::~Cart() {
    clearCart();
}

void Cart::clearCart() {
    delete[] courses;
    courses = nullptr;

    if (schedules != nullptr) {
        for (int i = 0; i < totalCount; ++i) {
            delete[] schedules[i];
        }
        delete[] schedules;
        schedules = nullptr;
    }

    totalCount = 0;
    totalCost = 0.0;
}

void Cart::addCourse(const Course& course, const char* selectedSchedule) {
    // Resize Course dynamic array
    Course* tempCourses = new Course[totalCount + 1];
    for (int i = 0; i < totalCount; ++i) {
        tempCourses[i] = courses[i];
    }
    tempCourses[totalCount] = course;
    delete[] courses;
    courses = tempCourses;

    // Resize schedules array of pointers
    char** tempSchedules = new char* [totalCount + 1];
    for (int i = 0; i < totalCount; ++i) {
        tempSchedules[i] = schedules[i];
    }
    tempSchedules[totalCount] = new char[strlen(selectedSchedule) + 1];
    strcpy(tempSchedules[totalCount], selectedSchedule);

    delete[] schedules;
    schedules = tempSchedules;

    totalCount++;
    totalCost += course.getPrice();
}

void Cart::listCourses() const {
    if (totalCount == 0) {
        std::cout << "\nYour cart is empty.\n";
        return;
    }

    std::cout << "\n Selected Courses in Cart \n";
    for (int i = 0; i < totalCount; ++i) {
        std::cout << i + 1 << ". " << courses[i].getCourseNumber()
            << " | " << courses[i].getCourseName()
            << " | Sched: " << schedules[i]
            << " | Price: $" << courses[i].getPrice() << "\n";
    }

    double tax = totalCost * TAX_RATE;
    double finalPrice = totalCost + tax;

    std::cout << "-----\n";
    std::cout << "Subtotal: $" << totalCost << "\n";
    std::cout << "Tax (13%): $" << tax << "\n";
    std::cout << "Total Cost: $" << finalPrice << "\n";
}

void Cart::checkout() {
    if (totalCount == 0) {
        std::cout << "\nNo courses in the cart\n";
    }
    else {
        std::cout << "\nThank you for your purchase!\n";
        clearCart();
    }
}

int Cart::getTotalCount() const { return totalCount; }