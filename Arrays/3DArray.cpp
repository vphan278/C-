#include <iostream>
using namespace std;

int main() {
    // 3D array: 2 layers, each layer is a 2x2 matrix
    int cube[2][2][2] = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };

    cout << "3D Array (2x2x2 cube):\n";

    for (int layer = 0; layer < 2; layer++) {
        cout << "\nLayer " << layer << ":\n";
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 2; col++) {
                cout << cube[layer][row][col] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}