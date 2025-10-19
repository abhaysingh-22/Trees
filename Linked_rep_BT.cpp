#include <iostream>
using namespace std;

// Node structure for linked representation
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;
    
public:
    BinaryTree() {
        root = NULL;
    }
    
    // Insert nodes to create a tree
    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
    
    // Inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    // Preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    // Postorder traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    
    // Public methods
    void insertValue(int value) {
        root = insert(root, value);
    }
    
    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
    
    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
    
    void displayPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    
    // Insert values
    tree.insertValue(50);
    tree.insertValue(30);
    tree.insertValue(70);
    tree.insertValue(20);
    tree.insertValue(40);
    tree.insertValue(60);
    tree.insertValue(80);
    
    // Display traversals
    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
    
    return 0;
}