#include <iostream>
using namespace std;

int main() {

    int choice;

    cout << "Enter a number (1-3): ";
    cin >> choice;

    switch (choice) {

    case 1:
        cout << "You chose ONE" << endl;
        break;

    case 2:
        cout << "You chose TWO" << endl;
        break;

    case 3:
        cout << "You chose THREE" << endl;
        break;

    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}