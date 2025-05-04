#include <iostream>
using namespace std;

class Stack {
private:
    const int size;    
    int* arr;          
    int top;

public:
    Stack(int s) : size(s) {
        arr = new int[size];
        top = -1;
    }

    
    void push(int value) {
        if (top >= size - 1) {
            cout << "Cannot push " << value << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << " Nothing to pop." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5); 
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
