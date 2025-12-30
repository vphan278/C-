#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // operator overloading
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(2, 3);
    Point p2(4, 5);

    Point p3 = p1 + p2;   // uses overloaded +

    p3.print();           // (6, 8)

    return 0;
}