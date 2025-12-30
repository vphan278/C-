#include <iostream>
using namespace std;

int main() {

    int arr[5];   // stack array

    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ":";
    }

    return 0;
}