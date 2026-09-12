#include <iostream>
using namespace std;

int queue[5], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % 5 == front)
        cout << "Queue Overflow\n";
    else {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % 5;

        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1)
        cout << "Queue Underflow\n";
    else {
        cout << "Deleted: " << queue[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 5;
    }
}

void display() {
    if (front == -1)
        cout << "Queue is empty\n";
    else {
        int i = front;

        while (true) {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

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

    enqueue(50);

    cout << "Queue after enqueue: ";
    display();

    return 0;
}
