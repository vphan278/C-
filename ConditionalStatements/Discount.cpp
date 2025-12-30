#include <iostream>
using namespace std;

int main() {

    float amount, discountedAmount;

    cout << "Enter bill amount: ";
    cin >> amount;

    if (amount >= 5000) {
        discountedAmount = amount - (amount * 0.20) ;   // 20% discount
    }
    else if (amount >= 2000 && amount < 5000) {
        discountedAmount = amount - (amount * 0.10);   // 10% discount
    }
    else {
        discountedAmount = amount - (amount * 0.05);   // 5% discount
    }

    cout << "Discounted bill amount = " << discountedAmount << endl;

    return 0;
}