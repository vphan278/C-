#include <iostream>
using namespace std;

int main(){

    int *arr = new int[5];  //heap array

    for(int i = 0; i < 5 ; i++){
        arr[i] = (i +1) * 10;
    }

    for (int i=0; i <5; i++){
        cout << arr[i] << ", ";   
    }

    delete[] arr;  //free heap array
    arr = nullptr;

    return 0;


}
