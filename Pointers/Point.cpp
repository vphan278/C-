#include <iostream>

using namespace std;

int main(){

    int *num1 = new int(11);
    int *num2 = num1;

    cout << "num1 = " << num1 <<endl; //num1 = 0x25ee43ef100
    cout << "num2 = " << num2 <<endl; //num2 = 0x25ee43ef100

}