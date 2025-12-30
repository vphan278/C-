#include <iostream>
using namespace std;

int main() {
    int arr[5];   // create an array of size 5

    // Input values from the user
    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    // Output values
    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nSum = " << sum << endl;

    return 0;
}






