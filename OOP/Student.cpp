#include <iostream>
#include <string>
using namespace std;

class Student{

    private:
        string name;
        int id;
        double gpa;

    public:
        //constructor
        Student(string name, int id, double gpa){
            this->name = name;
            this->id = id;
            this->gpa = gpa;
        }

        //Setters and Getters
        void setName(string name){
            this->name = name;
        }

        void setID(int id){
            this->id = id;
        }

        void setGPA(double newGPA){
            this->gpa = newGPA;
        }


        //getter
        string getName(){
            return name;
        }

        int getID(){
            return id;
        }

        double getGPA(){
            return gpa;
        }


};

//Main
int main(){

    Student s1("Vinh", 123, 3.8);
    Student s2("Mike", 456, 3.5);
   

    cout << "Name: " << s1.getName() << endl;
    cout << "ID: " << s1.getID() << endl;
    cout << "GPA: " << s1.getGPA() << endl;

    cout << "Name: " << s2.getName() << endl;
    cout << "ID: " << s2.getID() << endl;
    cout << "GPA: " << s2.getGPA() << endl;


    //Heao object (pointer)
    Student* s3 = new Student("Heap", 987, 2.0);
    cout << "Name: " << s3->getName() << endl;
    cout << "ID: " << s3->getID() << endl;
    cout << "GPA: " << s3->getGPA() << endl;


    delete s3;

    return 0;
}

