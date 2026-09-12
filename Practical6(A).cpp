#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert after a given node
void insertAfter(int givenValue, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != givenValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Given node not found\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display linked list
void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    insertBeginning(20);
    insertBeginning(10);

    insertEnd(30);
    insertEnd(40);

    cout << "Linked List: ";
    display();

    insertAfter(20, 25);

    cout << "After inserting 25 after 20: ";
    display();

    return 0;
}
