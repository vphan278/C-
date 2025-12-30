#include <iostream>

int main(){

    int sum = 0;
    int A[] = {2,4,6,7,9};

    for(int x: A){

        sum = sum + x;
        std:: cout << x << std::endl;
    }

    return 0;

}