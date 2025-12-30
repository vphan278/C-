#include <iostream>
using namespace std;

int main() {

    int a, b, c;

    cout << "Enter three numbers( in order: a , b , c): ";
    cin >> a >> b >> c;

     // Print the values with labels first
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    int max = a;   // assume a is the largest
    char maxLetter = 'a';

    if (b > max) {
        max = b;
        maxLetter = 'b';
    }

    if (c > max) {
        max = c;
        maxLetter = 'c';
    }

    cout << "The maximum is: " << maxLetter << " = " << max << endl;

    return 0;
}
