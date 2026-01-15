#include <iostream>
using namespace std;

class DNode{

    public:
        char data;
        DNode *prev;
        DNode *next;

        DNode(char val) : data(val), prev(nullptr), next(nullptr){}

};

DNode *buildDoublyList(){

    DNode *A = new DNode('A');
    DNode *B = new DNode('B');
    DNode *C = new DNode('C');
    DNode *D = new DNode('D');
    DNode *E = new DNode('E');

    A->next = C;
    B->prev = C; B->next = D;
    C->prev = A; C->next = B;
    D->prev = B; D->next = E;
    E->prev = D;

    return A; // head


}


void printDoublyList(DNode *head){
    while(head){
        cout << head->data << "<-> ";
        head = head->next;
    }
    cout << "null\n";

}

int main() {

    DNode* head = buildDoublyList();  // build list
    printDoublyList(head);            // print list

    return 0;
}