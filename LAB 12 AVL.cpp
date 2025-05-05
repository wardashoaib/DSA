#include <iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVL {
public:
    Node* root = nullptr;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    AVL tree;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Inorder Traverse\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.root = tree.insert(tree.root, value);
                break;
            case 2:
                cout << "Inorder: ";
                tree.inorder(tree.root);
                cout << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
