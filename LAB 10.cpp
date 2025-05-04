//LAB 10

#include <iostream>
using namespace std;

class ArrayStack {
    int stack[5];  
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(int value) {
        if (top < 4) {
            stack[++top] = value;
            cout << "Pushed Array: " << value << endl;
        } else {
            cout << "Stack is full Array \n";
        }
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped Array: " << stack[top--] << endl;
        } else {
            cout << "Stack is empty Array \n";
        }
    }

    void display() {
        cout << "Stack Array: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedListStack {
    Node* top;

public:
    LinkedListStack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed LinkedList: " << value << endl;
    }

    void pop() {
        if (top != NULL) {
            cout << "Popped LinkedList : " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Stack is empty LinkedList \n";
        }
    }

    void display() {
        cout << "Stack LinkedList: ";
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    ArrayStack arrayStack;
    LinkedListStack linkedListStack;

    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.display();
    arrayStack.pop();
    arrayStack.display();

    cout << endl;

    linkedListStack.push(10);
    linkedListStack.push(20);
    linkedListStack.display();
    linkedListStack.pop();
    linkedListStack.display();

    return 0;
}
