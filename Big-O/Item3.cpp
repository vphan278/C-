#include <iostream>
using namespace std;


//O(log n) 

void printItems(int n){

    int steps = 0;

    while(n > 1){
        cout << n <<endl; // 16 -> 8-> 4 ->2 -> 1

        n = n/2; //cut the problem in half each time
        steps ++;
    }
    cout <<"Steps: " << steps <<endl;
}

int main(){
    printItems(16);

    return 0;
}