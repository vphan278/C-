#include <iostream>
using namespace std;

class Student{

    private:
        string name;
        int age;

    public:
        void setName(string n){
            name = n;
        }

        void setAge(int a){
            age = a;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age <<endl;
        }

};

int main(){

    Student s1;

    s1.setName("Vinh");
    s1.setAge(25);

    s1.display(); // Name: Vinh   Age: 25

    return 0;

}