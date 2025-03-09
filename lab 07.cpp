#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        display();
    }
    
    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        display();
    }
    
    void insertAtNth(int val, int pos) {
        if (pos == 1 || !head) {
            insertAtFirst(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next && i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        if (!newNode->next) tail = newNode;
        display();
    }
    
    void insertAtCenter(int val) {
        if (!head) {
            insertAtFirst(val);
            return;
        }
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        insertAtNth(val, (fast ? 2 : 1));
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void displayReverse() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtNth(15, 2);
    list.insertAtCenter(25);
    
    cout << "Ordered List: ";
    list.display();
    
    cout << "List in reverse order: ";
    list.displayReverse();
    
    return 0;
}
