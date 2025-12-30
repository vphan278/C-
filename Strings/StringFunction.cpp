#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {

    char s1[20] = "Good";  //s[20], 20 means how many characters it can hold
    char s2[10] = " Morning";

    strcat(s1,s2);
    cout << s1 << endl; 

    //////////////////////////////////////////////////////////////////
    string a = "Vinh";
    string b = a;

    //length
    int len = a.length();
    cout << len <<endl; //4
    
    //Access characters
    char c = a[0];
    a[1] = 'i';

    cout << c << endl; //V
    cout << a[1] << endl; //i

    //Modify characters
    a[0] = 'Z';
    
    cout << a[0] << endl; //Z
    
    //Concatenate
    string full = a + " Phan";

    cout << full << endl;// Zinh Phan

    //Substring
    string sub = a.substr(1, 3);

    cout << sub << endl; //inh

    //Replace
    string r = "I love cats";
    r.replace(7, 4, "dogs");   // I love dogs

    cout << r << endl;

    //find
    size_t pos = a.find("inh");
    if(pos !=string::npos){
        cout << "Found at " << pos << endl; // Found at 1
    }

    //Insert
    a.insert(0, "Mr ");

    cout << a << endl; // Mr Vinh

    //Erase
    a.erase(0, 4);
    
    cout << a << endl; //inh

    //Append
    string w = "Hello";
    w.append(" World");

    cout << w << endl; // Hello World

    //Stacks and Queues
    stack<string> st;
    queue<string> q;

    st.push("apple");
    q.push("hello");

    cout << st.top() << endl; // apple
    cout << q.front() << endl; //hello

    //Vectors
    vector<string> fruit = {"grapes", "oranges"};

    fruit.push_back("apples");
    for(string f : fruit){
        cout << f << ", "; //grapes , oranges, apples
    }
    cout << endl;

    //string
    string fruits = "grapes, oranges";

    fruits += ", apples";   // add more fruit

    cout << fruits << endl; // grapes, oranges, apples

    //String
    string g = "Airplane";

    cout << g << endl; //Airplane

    return 0;




}