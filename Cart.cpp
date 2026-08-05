#include "Cart.h"
#include <cstring>

using namespace std;

Cart::Cart() {
    courses = nullptr;
    schedules = nullptr;
    totalCount = 0;
    totalCost = 0.0;
}

Cart::~Cart() {
    clearCart(); // a 2 step process for 2d arrays structures
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

// Getting the total before completing the purchase
void Cart::listCourses() const {
    if (totalCount == 0) {
        cout << "\nYour cart is empty.\n";
        return;
    }

    cout << "\nSelected Courses in Cart\n";
    for (int i = 0; i < totalCount; ++i) {
        cout << i + 1 << ". " << courses[i].getCourseNumber()
            << " | " << courses[i].getCourseName()
            << " | Sched: " << schedules[i]
            << " | Price: $" << courses[i].getPrice() << "\n";
    }

    double tax = totalCost * TAX_RATE;
    double finalPrice = totalCost + tax;

    cout << "_______\n";
    cout << "Subtotal: $" << totalCost << "\n";
    cout << "Tax (13%): $" << tax << "\n";
    cout << "Total Cost: $" << finalPrice << "\n";
}

// Checking out with cart
void Cart::checkout() {
    if (totalCount == 0) {
        cout << "\nNo courses in the cart\n";
    }
    else {
        cout << "\nThank you for your purchase!\n";
        clearCart();
    }
}

int Cart::getTotalCount() const { return totalCount; }
