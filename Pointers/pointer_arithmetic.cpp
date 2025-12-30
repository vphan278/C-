#include <iostream>
using namespace std;

int main(){

    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // points to arr[0]

    cout << *p << " is p at index 0 "<< endl;   // 10
    cout << *(p + 1) << " is p at index 1 " << endl; // 20
    cout << *(p + 2) << " is p at index 2 "<< endl; //30


    for(int i=0; i<5; i++){
        cout << arr + i << " = " << *(arr + i) << endl; // 0x9e4dffff50 = 10, 0x9e4dffff54 = 20, etc ....
    }

    //arr = address and *arr is index
 
    return 0;

}