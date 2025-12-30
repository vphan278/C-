#include <iostream>
using namespace std;

// Create a new type name "Length" for double
typedef double Length;

int main() {

    Length width = 5.5;   // same as double width
    Length height = 10.2; // same as double height

    Length area = width * height;

    cout << "Width  = " << width << endl;
    cout << "Height = " << height << endl;
    cout << "Area   = " << area << endl;

    return 0;
}
