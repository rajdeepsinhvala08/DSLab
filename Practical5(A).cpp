#include <iostream>
using namespace std;

int queue[100], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99)
        cout << "Queue Overflow\n";
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
        cout << "Deleted: " << queue[front++] << endl;
}

void display() {
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "Queue after dequeue: ";
    display();

    return 0;
}
