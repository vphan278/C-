
#include <iostream>

using namespace std;

//Step 1: Define a Node
struct Node{
    int data;
    Node *next;

};

int main(){

    //Step 2: Create nodes
    Node *head = new Node{40, nullptr};
    head->next = new Node{50, nullptr};
    head->next->next = new Node{60, nullptr};
    head->next->next->next = new Node{70, nullptr};

    //--------------------------------------------------------------//
    //Traverse the list
    cout << "Linked List: " <<endl;

    Node *curr = head;

    while(curr !=nullptr){
        cout << curr->data << ", ";  //Linked List: 40,50,60,70
        curr = curr->next;
    }
    cout <<endl;
    

    //-------------------------------------------------------------//
    //INSERT AT HEAD-after while loop
    Node *newNode = new Node{30, head};
    head = newNode;

    cout << "After insert at head: " <<endl;
    curr = head;

    while(curr !=nullptr){
        cout << curr->data << ", ";  //After insert at head: 30, 40,50,60,70
        curr = curr->next;
    }
    cout <<endl;


    //------------------------------------------------------------//
    //INSERT AT TAIL
    Node* newTail = new Node{80, nullptr};
    curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newTail;

    cout << "After insert at tail:" << endl;
    curr = head;

    while (curr != nullptr) {
        cout << curr->data << ", "; //After insert at tail: 30, 40, 50, 60, 70, 80
        curr = curr->next;
    }
    cout << endl;

   
   

   

    return 0;

}