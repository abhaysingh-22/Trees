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

// Check if tree is BST
bool isBST(Node* node, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (node == NULL) return true;
    
    // Check if current node violates BST property
    if (node->data <= minVal || node->data >= maxVal) return false;
    
    // Check left and right subtrees
    return isBST(node->left, minVal, node->data) && 
           isBST(node->right, node->data, maxVal);
}

int main() {
    // Create BST:      5
    //                /   \
    //               3     7
    //              / \   / \
    //             2   4 6   8
    
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    
    if (isBST(root)) {
        cout << "Tree is a Binary Search Tree!" << endl;
    } else {
        cout << "Tree is NOT a Binary Search Tree!" << endl;
    }
    
    return 0;
}