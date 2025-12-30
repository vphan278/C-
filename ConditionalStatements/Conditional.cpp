#include <iostream>
using namespace std;

int main(){

    int number;

    cout << "Enter a number(click enter)";
    cin >> number;

    //Simple if
    if(number > 0){
        cout << number << " :is positive. " << endl;
    }

    //if/else
    if(number % 2 == 0){
        cout << number << " :is even" << endl;
    }
    else{
        cout << number << " : is odd. " << endl;
    }

    //if / else if / else
    if(number < 0){
        cout << "It is a negative number"<< endl;
    }
    else if(number ==0){
        cout << "It is zero" << endl;
    }
    else{
        cout << "It is a positive number." << endl;
    }

    // Bonus: switch statement
    switch (number) {
        case 1: cout << "You entered ONE." << endl; break;
        case 2: cout << "You entered TWO." << endl; break;
        case 3: cout << "You entered THREE." << endl; break;
        default: cout << "Number is not 1, 2, or 3." << endl;
    }

    return 0;


}