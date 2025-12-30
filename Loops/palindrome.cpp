#include <iostream>
using namespace std;

int main() {
    int n, original, rev = 0;

    cout << "Enter a number: ";
    cin >> n;

    original = n;  // save the original number

    while (n != 0) {
        int digit = n % 10;       // take last digit
        rev = rev * 10 + digit;   // build reversed number
        n = n / 10;               // remove last digit
    }

    if (rev == original)
        cout << "Palindrome\n";
    else
        cout << "Not a palindrome\n";

    return 0;
}