#include <iostream>

using namespace std;

int main(){

    float r, volume, h;



    cout << "Enter Radius and height: ";

    cin >> r >> h;

    volume = 3.1425f * r *r * h;
    cout << "Volume is(V=3.1425 * r *r *h): "<< volume << endl;
    return 0;


}