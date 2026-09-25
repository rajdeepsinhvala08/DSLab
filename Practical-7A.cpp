#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int x) {
    Node* n = new Node;
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* t = head;
    while (t->next != head)
        t = t->next;

    n->next = head;
    t->next = n;
    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* t = head;
    while (t->next != head)
        t = t->next;

    t->next = n;
    n->next = head;
}

// Insert after given node
void insertAfter(int a, int x) {
    if (head == NULL)
        return;

    Node* t = head;

    do {
        if (t->data == a) {
            Node* n = new Node;
            n->data = x;
            n->next = t->next;
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

// Display
void display() {
    if (head == NULL)
        return;

    Node* t = head;

    do {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != head);

    cout << "(back to head)\n";
}

int main() {
    insertBeg(20);
    insertBeg(10);
    insertEnd(40);
    insertAfter(20, 30);

    display();

    return 0;
}