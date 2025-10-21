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

// PostOrder traversal: Left -> Right -> Root
void postorder(Node* node) {
    if (node == NULL) return;
    
    postorder(node->left);           // Traverse Left
    postorder(node->right);          // Traverse Right
    cout << node->data << " ";       // Visit Root
}

int main() {
    // Create tree:    1
    //                / \
    //               2   3
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    cout << "PostOrder Traversal: ";
    postorder(root);
    cout << endl;
    
    return 0;
}
