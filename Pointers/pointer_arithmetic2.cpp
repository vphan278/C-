#include <iostream>
using namespace std;

void PointerArith(){

    int A[] = {2,4,6,8,10,12};
    int *p=A;

    //point at 2
    cout << *p << endl;

    //move pointer to next location to print 4
    p++;
    cout << *p << endl;;

    //move pointer to point on 10
    p = p + 3;
    cout << *p << endl;    

  
    //point to 2
    p = p -4;
    cout << *p << endl;

    //address at p0
    cout << p << endl; ///0xfef8.....

    cout << p+2 << endl;// 0x12fe....


    for(int i=0; i<5; i++){
        cout << A[i] <<endl; //[2,4,6,8,10,12]
    }
    
    cout << "[";
    for (int ii = 0; ii < 6; ii++) {
        cout << A[ii];
        if (ii < 5) {
            cout << ",";
        }
    }
    cout << "]" << endl;



}

int main(){
    PointerArith();
    return 0;
}