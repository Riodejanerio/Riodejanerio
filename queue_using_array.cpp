#include <bits/stdc++.h>
using namespace std;

#define Qsize 100000
int myQ[Qsize];
int front = -1;
int rear  = -1;

// Enqueue function
void enQueue(int data) {
    if ((rear + 1) % Qsize == front) { // Queue is full
        cout << "Queue Overflow!" << endl;
        return;
    }

    if (front == -1 && rear == -1) { // Queue is empty
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % Qsize; // Circular increment
    }

    myQ[rear] = data;
    cout << "Enqueued: " << data << endl;
}

// Dequeue function
int deQueue() {
    if (front == -1) { // Queue is empty
        cout << "Queue Underflow!" << endl;
        return -1;
    }

    int y = myQ[front];

    if (front == rear) { // Only one element
        front = rear = -1;
    }
    else {
        front = (front + 1) % Qsize; // Circular increment
    }

    cout << "Dequeued: " << y << endl;
    return y;
}


void top() {
    if (front == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front element: " << myQ[front] << endl;
}


int main() {
    enQueue(1);
    top();
    deQueue();
    top();
    deQueue();
    enQueue(2);
    top();

    return 0;
}
