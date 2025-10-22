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

// Insert value into BST
Node* insertBST(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
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
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 6);
    root = insertBST(root, 8);

    cout << "Root of BST: " << root->data << endl;
    cout << "InOrder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}