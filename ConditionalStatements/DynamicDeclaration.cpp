#include <iostream>
using namespace std;

//Dynamic Declaration of a Single Variable
//p = the address
// *p = the dynamic memory stored at that address

int main(){

    int *p = new int; //dynamically declare an integer
    *p = 25;   // assign value

    cout << "Value: " << *p << endl;

    delete p;  // free memory
    
    return 0;

}

//new int allocates memory on the heap
//p holds the address
//*p accesses the value
//delete frees the memory