#include <iostream>
using namespace std;

int main() {

    int a = 12;   // 1100
    int b = 10;   // 1010

    cout << "a = 12  (1100)" << endl;
    cout << "b = 10  (1010)" << endl << endl;

    // Bitwise AND ( 1 and 1 =1, else is 0)
    cout << "a & b = " << (a & b) << endl;   // 1000 = 8

     // Bitwise OR
    cout << "a | b = " << (a | b) << endl;   // 1110 = 14

    // Bitwise XOR
    cout << "a ^ b = " << (a ^ b) << endl;   // 0110 = 6

    // Bitwise NOT
    cout << "~a = " << (~a) << endl;         // flips all bits (32-bit result)

    // Left shift
    cout << "a << 1 = " << (a << 1) << endl; // 1100 << 1 = 11000 = 24


    // Right shift
    cout << "a >> 1 = " << (a >> 1) << endl; // 1100 >> 1 = 110 = 6
    
    return 0;
}