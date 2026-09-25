#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node* t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
}

void insertAfter(int a, int x) {
    Node* t = head;

    while (t != NULL && t->data != a)
        t = t->next;

    if (t != NULL) {
        Node* n = new Node;
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void deleteBeg() {
    if (head == NULL)
        return;

    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* t = head;
    while (t->next->next != NULL)
        t = t->next;

    delete t->next;
    t->next = NULL;
}

void deleteAfter(int a) {
    Node* t = head;

    while (t != NULL && t->data != a)
        t = t->next;

    if (t != NULL && t->next != NULL) {
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }
}

void display() {
    Node* t = head;

    while (t != NULL) {
        cout << t->data << " -> ";
        t = t->next;
    }

    cout << "NULL\n";
}

int main() {
    insertBeg(20);
    insertBeg(10);
    insertEnd(40);
    insertAfter(20, 30);

    cout << "List: ";
    display();

    deleteBeg();
    deleteEnd();
    deleteAfter(20);

    cout << "After deletion: ";
    display();

    return 0;
}