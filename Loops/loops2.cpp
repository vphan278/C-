#include <iostream>
using namespace std;


int main(){

    //Multiplication able
    int n, i;
    cout << "Enter n: ";
    cin >> n;

    for(i=1; i<=4; i++){
        cout << n << "x" << i << " = " << n * i;
        cout << endl;
    }

    //Sum of N
    int nn, ii = 1, sum =0;
    cout << "Enter nn: ";
    cin >> nn;

    for(ii =1; ii <= nn; ii++){
        sum = sum + ii;
    }
    cout << "sum nn number is: " << sum;

    


    return 0;

}