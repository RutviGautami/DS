#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

// Build the tree interactively
struct Node* buildTree() {
    int val;
    printf("Enter node value (or -1 for no node): ");
    if (scanf("%d", &val) != 1 || val == -1) {
        return NULL;
    }

    struct Node* root = newNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = buildTree();
    printf("Enter right child of %d:\n", val);
    root->right = buildTree();
    return root;
}

// Compute the height of the tree
int height(struct Node *root) {
    if (root == NULL){
        return 0;
    } 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Check if the tree is balanced
bool isBalanced(struct Node *root) {
    if (root == NULL) {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

// Wrapper to print balance status
void checkBalance(struct Node* root) {
    if (isBalanced(root)) {
        printf("The tree is BALANCED.\n");
    } else {
        printf("The tree is NOT BALANCED.\n");
    }
}

// Main function
int main() {
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();

    checkBalance(root);

    return 0;
}