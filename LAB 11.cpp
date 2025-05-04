//LAB 11


#include <iostream>
using namespace std;

class ArrayQueue {
    int queue[5];
    int front, rear;

public:
    ArrayQueue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == 4) {
            cout << "Queue is full (Array)\n";
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = value;
        cout << "Enqueued (Array): " << value << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty (Array)\n";
            return;
        }
        cout << "Dequeued (Array): " << queue[front++] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty (Array)\n";
            return;
        }
        cout << "Queue (Array): ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListQueue {
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued (LinkedList): " << value << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty (LinkedList)\n";
            return;
        }
        cout << "Dequeued (LinkedList): " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty (LinkedList)\n";
            return;
        }
        cout << "Queue (LinkedList): ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue arrayQueue;
    LinkedListQueue linkedListQueue;

    arrayQueue.enqueue(1);
    arrayQueue.enqueue(2);
    arrayQueue.display();
    arrayQueue.dequeue();
    arrayQueue.display();

    cout << endl;

    linkedListQueue.enqueue(10);
    linkedListQueue.enqueue(20);
    linkedListQueue.display();
    linkedListQueue.dequeue();
    linkedListQueue.display();

    return 0;
}
