#include <iostream>
using namespace std;

//Vinh Phan
//CIS-22C: C++ Data Structures and Algorithms
//CRN 33571


// Starting layout
//       [A]
//        ↑
//  [D] ← X → [B]
//        ↓
//       [C]

//Pointer Manipulation
// temp  = north
// north = west
// west  = south
// south = east
// east  = temp

class Rotor {

    public: 
        char north = 'A';
        char east = 'B';
        char south = 'C';
        char west = 'D';
        int degrees = 0;

    //Constructor- initial layout
    Rotor(){}
    
    char rotateClockwise() {
        //initial layout
        char temp = north;
        north = west;
        west  = south;
        south = east;
        east  = temp;

        degrees = (degrees + 90) % 360;
        return north;
    }
    
};

void printRotor(Rotor& r) {
    for (int i = 0; i < 4; i++) {
        cout << "After rotation each 90 degree rotation, north: " << r.rotateClockwise() << " "; //After rotation each 90 degree rotation, north: D
    }
    cout << endl;
}

 //First clockwise rotation

    //       [D]
    //        ↑
    //  [C] ← X → [A]
    //        ↓
    //       [B]

int main(){

    //initial layout
    Rotor r;
    printRotor(r);

    return 0;

    
}

    


