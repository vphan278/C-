#include <iostream>
using namespace std;


class LightBulb{

    private:
        bool isOn;

    public:
        //constructor
        LightBulb(){
            isOn = false;
        }

        //setter and getters 
        void turnOn(){   //inline function
            isOn = true;
        }

        void turnOff(){ //inline function
            isOn = false;
        }

        bool getStatus(){
            return isOn;
        }

};

int main(){

    //Create object on the Heap
    LightBulb *pBulb = new LightBulb();

    pBulb->turnOn();

    if(pBulb->getStatus()){
        cout << "The light is ON " <<endl; // The light is ON
    }
    else{
        cout << "The light is OFF" << endl;
    }

    pBulb->turnOff();
    cout << "Light is OFF. " <<endl; // Light is OFF

    delete pBulb;

    return 0;

}