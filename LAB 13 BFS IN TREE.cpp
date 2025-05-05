#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    Node* insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = new Node(val);
                return temp->left;
            } else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = new Node(val);
                return temp->right;
            } else {
                q.push(temp->right);
            }
        }
        return nullptr;
    }

    void BFS() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(1); 
    tree.insert(2);
    tree.insert(3); 
    tree.insert(4); 
    tree.insert(5); 

    cout << "BFS Traversal: ";
    tree.BFS();
    cout << endl;

    return 0;
}
