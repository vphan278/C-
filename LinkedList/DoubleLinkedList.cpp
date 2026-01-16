#include <iostream>
#include <list>
using namespace std;

//Vinh Phan
//CIS-22C: C++ Data Structures and Algorithms
//CRN 33571

class DNode {
    public:
        char data;
        DNode* prev;
        DNode* next;
        DNode(char v) : data(v), prev(nullptr), next(nullptr) {}
    };

class DoubleLinkedList {

    private:
        DNode* head;

    public:
        DoubleLinkedList() : head(nullptr) {}

         // Destructor 
        ~DoubleLinkedList() {
             clear();
        }

        void insertFront(char v) {
            DNode* n = new DNode(v);
            if (head) {
                n->next = head;
                head->prev = n;
            }
            head = n;
        }

        void insertBack(char v) {
            DNode* n = new DNode(v);
            if (!head) { head = n; return; }
            DNode* c = head;
            while (c->next) c = c->next;
            c->next = n;
            n->prev = c;
        }

        void swap() {
            int count = 0;
            for (DNode* c = head; c; c = c->next) count++;

            DNode* c = head;
            for (int i = 0; i < count / 2; i++) c = c->next;

            if (!c || !c->prev) return;

            DNode* left = c->prev;
            DNode* a = left->prev;
            DNode* d = c->next;

            if (a) a->next = c;
            c->prev = a;

            c->next = left;
            left->prev = c;

            left->next = d;
            if (d) d->prev = left;

            if (left == head) head = c;
        }

        void print() {
            for (DNode* c = head; c; c = c->next)
                cout << c->data << " <-> ";
            cout << "null\n";
        }

        // Clear entire list
        void clear() {
            while (head) {
                DNode* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    DoubleLinkedList list;

    list.insertBack('A');
    list.insertBack('B');
    list.insertBack('C');
    list.insertBack('D');
    list.insertBack('E');

    list.print();       // A <-> B <-> C <-> D <-> E
    list.swap();        // swap C with B
    list.print();       // A <-> C <-> B <-> D <-> E
}