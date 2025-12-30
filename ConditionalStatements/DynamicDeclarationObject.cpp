#include <iostream>
using namespace std;

class Student{
    public:
        void sayHello(){
            cout << "Hello, I'm a student!" << endl;
        }

};

int main(){

    Student *s = new Student;   //dynamically allocate an object
    s-> sayHello();

    delete s;

    return 0;

}
