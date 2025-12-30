#include <iostream>
using namespace std;


class Counter{

    private:
        int count;  //data hidden

    public:

        //Constructor
        Counter(){
            count = 0;
        }

        //Setter and Getter
        void setIncrement(){
            count++;
        }

        int getCount(){
            return count;
        }
    
};

int main(){

    //Create an object of the class
    Counter c1;

    c1.setIncrement();
    cout << "Count = " << c1.getCount() <<endl; //Count = 1

    c1.setIncrement();
    cout << "Count = " << c1.getCount() <<endl; //Count = 2

    return 0;

}








