//LAB 10 LINKEDLIST
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; 

public:

    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            Node* temp = top;
            cout << top->data << " popped from stack." << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }


    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};


int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n Stack Menu: " << endl;
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
