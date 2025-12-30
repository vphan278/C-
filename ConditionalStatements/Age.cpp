#include <iostream>
using namespace std;

int main(){

    int age;

    cout << "Enter your age. ";
    cin >> age;

    if(age >= 12 && age <=50){
        cout<< "You are young.";
    }
    else{
        cout << "You are not young";
    }

    return 0;
}