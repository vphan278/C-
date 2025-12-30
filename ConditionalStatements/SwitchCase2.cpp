#include <iostream>
using namespace std;

int main() {

    char grade;
    cout << "Enter your grade (A, B, C): ";
    cin >> grade;

    switch (grade) {

    case 'A':
        cout << "Excellent!" << endl;
        break;

    case 'B':
        cout << "Good job!" << endl;
        break;

    case 'C':
        cout << "You passed." << endl;
        break;

    default:
        cout << "Invalid grade." << endl;
    }

    return 0;
}