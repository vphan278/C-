#include <iostream>
using namespace std;

int main() {
    int matrix[2][2];  // a 2x2 array

    // Input values
    cout << "Enter 4 numbers for the 2x2 matrix:\n";
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            cin >> matrix[row][col];
        }
    }

    // Output matrix
    cout << "\n2x2 Matrix:\n";
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}