#include <iostream>
#include <string>
using namespace std;

int main() {
    string g;

    cout << "Enter a string: ";
    getline(cin, g);

    cout << "You entered: " << g << endl;
    cout << "Length of string: " << g.length() << endl;

    // Concatenate another string
    string extra = "!!!";      // You can change this
    string combined = g + extra;

    cout << "After concatenation: " << combined << endl;


    return 0;
}