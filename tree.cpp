#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in the tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to print the tree in-order (left, root, right)
void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->value << " ";
        printInOrder(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the binary tree
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);

    // Print the tree in-order
    cout << "In-order traversal: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
