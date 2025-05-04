#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front, rear;

public:
    Queue(int queueSize) {
        size = queueSize;
        arr = new int[size]; 
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full (Overflow)!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty (Underflow)!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        front++;
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size); 
    int choice, value;

    do {
        cout << " Queue Menu: " << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
