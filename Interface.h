#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    virtual void showMenu() = 0; // Pure virtual function for polymorphism
    virtual ~Interface() {}

protected:
    // Common input validation helpers
    int getValidIntInput(int minOption, int maxOption);
    void clearInputBuffer();
};

#endif