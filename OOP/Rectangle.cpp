#include <iostream>
using namespace std;


class Rectangle {

    private:

        int length;
        int width;

    public:

        //Constructor
        Rectangle(int length, int width){
            this->length = length;
            this->width = width;
        }

        int area(){
            return length*width;
        }

        int perimeter(){
            return 2 * (length + width);
        }

};


int main(){
    Rectangle r(5.0, 3.0);

    cout << "Area: " << r.area() << endl; // Area: 15
    cout << "Perimeter: " << r.perimeter() <<endl;  //Perimeter: 16

    return 0;
}