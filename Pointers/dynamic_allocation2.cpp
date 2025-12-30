#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++ ) {
        arr[i] = i * 2;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // 0*2 = 0, 1*2 = 2, 2*2 = 4, 3*2  =6, 4*2  =8 
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}