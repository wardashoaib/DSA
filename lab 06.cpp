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
        Node* newNode = new Node(val);
        if (pos == 1 || !head) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; temp->next && i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        display();
    }
    
    void deleteFirstNode() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        display();
    }
    
    void deleteLastNode() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        display();
    }
    
    void deleteNthNode(int n) {
        if (!head) return;
        if (n == 1) {
            deleteFirstNode();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next && i < n - 1; i++) temp = temp->next;
        if (!temp->next) return;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        display();
    }
    
    void deleteCenterNode() {
        if (!head || !head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* slow = head, *fast = head, *prev = nullptr;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = slow->next;
            delete slow;
        }
        display();
    }
    
    void display() {
        Node* temp = head;
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
    list.insertAtPosition(30, 3);
    list.insertAtPosition(40, 4);
    list.insertAtPosition(50, 5);
    
    list.deleteFirstNode();
    list.deleteLastNode();
    list.deleteNthNode(2);
    list.deleteCenterNode();
    
    return 0;
}
