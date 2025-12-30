#include <iostream>
using namespace std;

int main(){

    int x = 10;
    int *p = &x;

    cout << x << endl; // 10
    cout << &x << endl; //address of x ( example:  ......)
    cout << p << endl; //  address of x ( example: 0xfc50bffdf4)
    cout << *p << endl; // 10  // value at address p

    return 0;
}