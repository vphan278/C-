#include <iostream>
using namespace std;


int main(){

    int n, i =1;

    cout << "Enter n: ";
    cin >> n;

    //While loop
    while (i <= n){
        cout << i << endl; // 
        i++;
    }

    //While loop
    int k = 0;
    while (k <4){
        cout << "Greeting\n"; //Greeting, Greeting, Greeting, Greeting
        k++;
    }

    //While loop
    int ii = 1;

    while (ii <= 3) {
        cout << ii << " " << endl;
        ii++;
    }


    //for loop
    cout << "[";
    for (int j = 1; j <= 5; j++) {
        cout << j ; // [1,2,3,4,5]

        if (j < 5){
            cout << ",";
        }
    }
    cout << "]" << endl;

    //loop 
    int l = 0;
    for(;;){
        cout << l << " Hello\n"; //0 Hello, 1 Hello , 2 Hello, 3 Hello
        l++;
        if( l > 3)
            break;
    }


    
    return 0;

}