#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        display();
    }

    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        display();
    }
    void insertAtNth(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 1 || !head) {
            insertAtFirst(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        display();
    }

    void insertAtCenter(int val) {
        if (!head || head->next == head) {
            insertAtFirst(val);
            return;
        }
        Node* slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        insertAtNth(val, 3);
    }
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void displayReverse() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        int arr[100], i = 0;
        do {
            arr[i++] = temp->data;
            temp = temp->next;
        } while (temp != head);
        
        cout << "Reverse: ";
        for (int j = i - 1; j >= 0; j--) {
            cout << arr[j] << " -> ";
        }
        cout << "(back to head)" << endl;
    }
};


int main() {
    CircularLinkedList clist;
    
    clist.insertAtFirst(10);
    clist.insertAtLast(30);
    clist.insertAtNth(20, 2);
    clist.insertAtCenter(25);
    
    cout << "Circular Linked List: ";
    clist.display();
    
    clist.displayReverse();
    
    return 0;
}
