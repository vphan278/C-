#include <iostream>
using namespace std;

int main() {

    int size;

    cout << "Enter number of elements: "; // say enter 5
    cin >> size;

    int A[size];

    cout << sizeof A << " bytes" <<endl;  // then it is 20....  1 element is 4 byte
    
    return 0;
}