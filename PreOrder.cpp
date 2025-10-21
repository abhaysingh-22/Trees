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

// PreOrder traversal: Root -> Left -> Right
void preorder(Node* node) {
    if (node == NULL) return;
    
    cout << node->data << " ";      // Visit Root
    preorder(node->left);            // Traverse Left
    preorder(node->right);           // Traverse Right
}

int main() {
    // Create tree:    1
    //                / \
    //               2   3
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    cout << "PreOrder Traversal: ";
    preorder(root);
    cout << endl;
    
    return 0;
}
