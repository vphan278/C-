#include <iostream>
using namespace std;

int main() {
    int* p = new int;   // allocate on heap
    *p = 25;

    cout << *p << endl;

    delete p;           // free memory
    p = nullptr;

    return 0;
}