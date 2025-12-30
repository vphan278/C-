#include <iostream>
using namespace std;

int main() {
    int x;

    do {
        cout << "Enter a number (0 to quit): ";
        cin >> x;
    } while (x != 0);

    cout << "Program ended.\n";
    return 0;
}