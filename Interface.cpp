
#include "Interface.h"
#include <iostream>
#include <limits>

using namespace std;

void Interface::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Interface::getValidIntInput(int minOption, int maxOption) {
    int choice;
    while (true) {
        if (cin >> choice && choice >= minOption && choice <= maxOption) {
            return choice;
        }
        cout << "Invalid choice. Please enter a valid option [" << minOption;
        for (int i = minOption + 1; i <= maxOption; ++i) {
            cout << ", " << i;
        }
        cout << "]: ";
        clearInputBuffer();
    }
}
