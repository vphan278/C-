#include <iostream>
using namespace std;

int main(){

    //1.Declare and initialize array
    int arr[10];  //capacity = 10
    int n =3;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    cout << "Initial array: ";
    for(int i = 0; i <n; i++){
        cout << arr[i] << ", ";
    }
    cout <<endl; //Initial array: 20, 20, 30,

    //--------------------------------------------------------------------------------------//

    //2.Get and Set
    cout << "get(1): " <<arr[1] <<endl;  // get(1): 20

    arr[1] = 99;
    cout << "After set(1,99): ";
    for(int i = 0; i<n; i++){
        cout << arr[i] << ", ";  //After set(1,99): 10,99,30
    }
    cout <<endl;

    //---------------------------------------------------------------------------------------//

    //3. Add at end(0,(1))
    arr[n] = 500;
    n++;

    cout << "AFter add at end: ";
    for(int i=0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout <<endl;

    //------------------------------------------------------------------------------------------//
    //4. Add at index(shift right)
    int index = 1;
    int value = 15;

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;

    cout << "After add(1,15): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ,"; // After add(1,15): 10, 15, 99, 30, 500
    }
    cout << endl;

    //---------------------------------------------------------------------------------------//
    //5. Remove at index(shift left)
    index = 2;

    for(int i = index; i< n -1; i++){
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "After remove(2)";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ", "; //After remove(2): 10,15,30,500
    }
    cout <<endl;
    
    //----------------------------------------------------------------------------------------//
    //6. Final Size

    cout <<"Final logical size: " << n << endl; //Final logical size: 4




    return 0;



}