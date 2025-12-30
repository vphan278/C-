#include <iostream>
using namespace std;

// Define an enum for the days of the week
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

int main() {

    Day today = WED;   // Assign a value from the enum

    cout << "Today is: ";

    switch (today) {
        case MON: cout << "Monday"; break;
        case TUE: cout << "Tuesday"; break;
        case WED: cout << "Wednesday"; break;
        case THU: cout << "Thursday"; break;
        case FRI: cout << "Friday"; break;
        case SAT: cout << "Saturday"; break;
        case SUN: cout << "Sunday"; break;
    }

    cout << endl;

    return 0;
}
