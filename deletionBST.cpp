#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Find minimum value node
Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Delete node from BST
Node* deleteBST(Node* root, int val) {
    if (root == nullptr) return nullptr;
    
    if (val < root->data) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteBST(root->right, val);
    } else {
        // Node to delete found
        
        // Case 1: No children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children
        Node* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = deleteBST(root->right, minRight->data);
        
        // Case 4: Root node deletion is handled by returning new root above
    }
    return root;
}

// Display BST in order
void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    Node* root = nullptr;
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Original BST: ";
    inorder(root);
    cout << endl;

    // Case 1: Delete non-root node
    root = deleteBST(root, 3);
    cout << "After deleting 3: ";
    inorder(root);
    cout << endl;
 
    // Case 4: Delete root node (5)
    root = deleteBST(root, 5);
    cout << "After deleting root 5: ";
    inorder(root);
    cout << endl;

    return 0;
}