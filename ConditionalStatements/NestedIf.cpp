#include <iostream>
using namespace std;

int main() {

    int m1, m2, m3;
    float Total, Avg;


    cout << "Enter your score of 3 subjects: ";
    cin >> m1 >> m2 >> m3;

    Total = m1 + m2 +m3;
    Avg = Total / 3;

    if( Avg >=60){
        cout << " Your average gives you an : A" << endl;
    }
    else if(Avg >= 35 && Avg < 60){
        cout << " Your average gives you a : B " << endl;
    }
    else{
        cout << " Your average gives you a : C " << endl;
    }




    return 0;
}