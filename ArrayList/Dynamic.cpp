#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    int* arr = new int[size];   // dynamic array

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; // free memory
}