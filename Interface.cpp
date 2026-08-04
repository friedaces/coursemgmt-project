
#include "Interface.h"
#include <iostream>
#include <limits>

using namespace std;

void Interface::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Interface::getValidIntInput(int minOption, int maxOption) {
    int choice;
    while (true) {
        if (std::cin >> choice && choice >= minOption && choice <= maxOption) {
            return choice;
        }
        std::cout << "Invalid choice. Please enter a valid option [" << minOption;
        for (int i = minOption + 1; i <= maxOption; ++i) {
            std::cout << ", " << i;
        }
        std::cout << "]: ";
        clearInputBuffer();
    }
}