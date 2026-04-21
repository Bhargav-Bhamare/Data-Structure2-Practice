#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class BST {
private:
    Node* root;

public:
    BST() {
        root = NULL;
    }

    // Iterative Insertion
    void insert(int val) {
        Node* newNode = new Node(val);

        if(root == NULL) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while(current != NULL) {
            parent = current;

            if(val < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if(val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    // Iterative Search
    bool search(int key) {
        Node* current = root;

        while(current != NULL) {
            if(current->data == key)
                return true;
            else if(key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    // Inorder
    void inorder(Node* node) {
        if(node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Preorder
    void preorder(Node* node) {
        if(node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder
    void postorder(Node* node) {
        if(node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Getter for root (for traversal)
    Node* getRoot() {
        return root;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(60);
    tree.insert(70);

    cout << "Traversals of BST:\n";

    cout << "\nPreorder:\n";
    tree.preorder(tree.getRoot());

    cout << "\nInorder:\n";
    tree.inorder(tree.getRoot());

    cout << "\nPostorder:\n";
    tree.postorder(tree.getRoot());

    cout << endl;

    return 0;
}