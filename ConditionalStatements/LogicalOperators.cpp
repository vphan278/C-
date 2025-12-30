// &&  And
// ||  Or
// !   Not

#include <iostream>
using namespace std;

int main(){

    int x;

    cout << "Enter a number: ";
    cin >> x;

    //Logical AND
    if( x > 0 && x < 100){
        cout << x << ": is betweem 0 and 100" << endl;
    }

    //Logical OR
    if(x < 0 || x > 100){
        cout << x << " : is outside the range of 0-100"<< endl;
    }

    // Logical NOT
    bool isEven = (x % 2 == 0);
    if (!isEven) {
        cout << x << " is odd." << endl;
    }
    else{
        cout << x << " : is even"<< endl;
    }


    return 0;


}