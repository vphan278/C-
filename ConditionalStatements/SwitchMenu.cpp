#include <iostream>
using namespace std;

int main() {

    int choice;

    do {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Add Numbers" << endl;
        cout << "2. Subtract Numbers" << endl;
        cout << "3. Multiply Numbers" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Sum = " << a + b << endl;
            break;
        }

        case 2: {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Difference = " << a - b << endl;
            break;
        }

        case 3: {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Product = " << a * b << endl;
            break;
        }

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}