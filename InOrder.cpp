#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// InOrder traversal: Left -> Root -> Right
void inorder(Node* node) {
    if (node == NULL) return;
    
    inorder(node->left);             // Traverse Left
    cout << node->data << " ";       // Visit Root
    inorder(node->right);            // Traverse Right
}

int main() {
    // Create tree:    1
    //                / \
    //               2   3
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    cout << "InOrder Traversal: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
