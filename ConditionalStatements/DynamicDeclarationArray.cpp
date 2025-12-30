#include <iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size]; //dynamic array

    //store values
    for (int i = 0; i < size; i++){
        arr[i] = i * 10;
    }

    //print values
    for(int i=0; i < size; i++){
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;


}