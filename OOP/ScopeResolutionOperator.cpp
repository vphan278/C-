#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;

public:
    Student(string name, int id);   // constructor declaration
    string getName();               // function declaration
    int getID();                    // function declaration
};

//constructor definition ---SCOPE RESOULTION OPERATOR
Student::Student(string name, int id){

    this->name = name;
    this->id = id;
}

//getName definition
string Student::getName(){
    return name;
}

//getID definition
int Student::getID(){
    return id;
}


int main(){

    Student s1("John", 123);

    cout << "Name:" << s1.getName() << endl; // Name: John
       cout << "ID: " << s1.getID() << endl; // ID: 123


}