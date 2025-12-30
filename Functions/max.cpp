#include <iostream>
using namespace std;

// function to find max of 3 numbers
int maxOfThree(int a, int b, int c) {
    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;

    return max;
}

int main() {
    int x = 10, y = 25, z = 15;

    int result = maxOfThree(x, y, z);
    cout << "Maximum: " << result << endl;

    return 0;
}