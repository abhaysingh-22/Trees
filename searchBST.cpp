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

// Search for element in BST
bool search(Node* node, int target) {
    if (node == NULL) return false;
    
    if (node->data == target) return true;
    else if (target < node->data) return search(node->left, target);
    else return search(node->right, target);
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
    
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    
    if (search(root, target)) {
        cout << "Element " << target << " found in BST!" << endl;
    } else {
        cout << "Element " << target << " NOT found in BST!" << endl;
    }
    
    return 0;
}