#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBeg(int x) {
    Node *n = new Node{x, head};
    if (head == NULL) n->next = n;
    else {
        Node *t = head;
        while (t->next != head) t = t->next;
        t->next = n;
    }
    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node *n = new Node{x, head};
    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }
    Node *t = head;
    while (t->next != head) t = t->next;
    t->next = n;
}

// Insert after given node
void insertAfter(int a, int x) {
    if (head == NULL) return;
    Node *t = head;
    do {
        if (t->data == a) {
            Node *n = new Node{x, t->next};
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

// Delete first
void deleteBeg() {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node *t = head;
    while (t->next != head) t = t->next;
    Node *d = head;
    head = head->next;
    t->next = head;
    delete d;
}

// Delete last
void deleteEnd() {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node *t = head;
    while (t->next->next != head) t = t->next;
    delete t->next;
    t->next = head;
}

// Delete after given node
void deleteAfter(int a) {
    if (head == NULL) return;
    Node *t = head;
    do {
        if (t->data == a && t->next != head) {
            Node *d = t->next;
            t->next = d->next;
            delete d;
            return;
        }
        t = t->next;
    } while (t != head);
}

// Display
void display() {
    if (head == NULL) return;
    Node *t = head;
    do {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != head);
    cout << "HEAD\n";
}

int main() {
    insertBeg(20);
    insertBeg(10);
    insertEnd(40);
    insertAfter(20, 30);

    display();

    deleteBeg();
    deleteEnd();
    deleteAfter(20);

    display();

    return 0;
}