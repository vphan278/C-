#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";
    cout << s << endl;


    //////////////////////////////////////////////////////
    // Print string info
    cout << "Length: " << s.length() << endl;
    cout << "First: " << s[0] << endl;
    cout << "Last: " << s[s.length() - 1] << endl;

    // Modify string
    s[0] = 'h';
    cout << "Changed: " << s << endl;

    // Concatenate
    cout << "Combined: " << s + "!!!" << endl;

    // Loop through characters
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;


    //////////////////////////////////////////////
    char letters[] = {'P', 'l', 'a', 'n', 'e'};

    // Print array
    for (int i = 0; i < 5; i++) {
        cout << letters[i] << " ";
    }
    cout << endl;

    //Print array
    string g = "Travel";

    cout << g[0] << endl;  // T
    cout << g[1] << endl;  // r

    return 0;


}