#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    
    void display() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " -> ";
        cout << "NULL" << endl;
    }
    
    void merge(SinglyLinkedList& other) {
        if (!head) head = other.head;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = other.head;
        }
    }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insert(int val) {
        DNode* newNode = new DNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void display() {
        for (DNode* temp = head; temp; temp = temp->next)
            cout << temp->data << " <-> ";
        cout << "NULL" << endl;
    }
    
    void merge(DoublyLinkedList& other) {
        if (!head) head = tail = other.head;
        else {
            tail->next = other.head;
            if (other.head) other.head->prev = tail;
            tail = other.tail;
        }
    }
};

int main() {
    SinglyLinkedList list1, list2;
    list1.insert(1);
    list1.insert(3);
    list1.insert(5);
    
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);
    
    cout << "Singly Linked List 1: "; list1.display();
    cout << "Singly Linked List 2: "; list2.display();
    
    list1.merge(list2);
    cout << "Merged Singly Linked List: "; list1.display();
    
    DoublyLinkedList dlist1, dlist2;
    dlist1.insert(10);
    dlist1.insert(30);
    dlist1.insert(50);
    
    dlist2.insert(20);
    dlist2.insert(40);
    dlist2.insert(60);
    
    cout << "1st Doubly Linked List: "; dlist1.display();
    cout << "2nd Doubly Linked List: "; dlist2.display();
    
    dlist1.merge(dlist2);
    cout << "Merged Doubly Linked List: "; dlist1.display();
    
    return 0;
}
