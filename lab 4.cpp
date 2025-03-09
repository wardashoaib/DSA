#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    
    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "No position!" << endl;
            return;
        }
        
        Node* newNode = new Node(val);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; temp && i < pos - 1; i++) {
                temp = temp->next;
            }
            if (!temp) {
                cout << "Position out" << endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        display();
    }
    
    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtPosition(10, 1);
    list.insertAtPosition(20, 2);
    list.insertAtPosition(30, 2);
    list.insertAtPosition(40, 5);
    list.insertAtPosition(50, 0);
    return 0;
}
