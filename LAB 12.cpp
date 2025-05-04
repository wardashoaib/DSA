//lab 12


#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    BSTNode* insert(BSTNode* root, int val) {
        if (root == NULL)
            return new BSTNode(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(BSTNode* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};


class AVLNode {
public:
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

class AVL {
public:
    int getHeight(AVLNode* n) {
        return n ? n->height : 0;
    }

    int getBalance(AVLNode* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        y->left = x->right;
        x->right = y;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        x->right = y->left;
        y->left = x;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    AVLNode* insert(AVLNode* root, int val) {
        if (root == NULL)
            return new AVLNode(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && val < root->left->data)
            return rightRotate(root);
        if (balance < -1 && val > root->right->data)
            return leftRotate(root);
        if (balance > 1 && val > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && val < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(AVLNode* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};



int main() {
    BST bst;
    AVL avl;
    BSTNode* bstRoot = NULL;
    AVLNode* avlRoot = NULL;


    int values[] = {30, 20, 40, 10};


    for (int i = 0; i < 4; i++)
        bstRoot = bst.insert(bstRoot, values[i]);

    cout << "BST Inorder: ";
    bst.inorder(bstRoot);
    cout << endl;


    for (int i = 0; i < 4; i++)
        avlRoot = avl.insert(avlRoot, values[i]);

    cout << "AVL Inorder: ";
    avl.inorder(avlRoot);
    cout << endl;

    return 0;
}
