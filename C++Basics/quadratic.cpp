#include <iostream>
#include <cmath>  

using namespace std;
int main() {
    float a, b, c, r1, r2;

    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    float d = b * b - 4 * a * c;   // discriminant

    if (d < 0) {
        cout << "No real roots (discriminant is negative)." << endl;
    }
    else {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);

        cout << "Roots are: " << r1 << " and " << r2 << endl;
    }

    return 0;
}