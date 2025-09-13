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

void smallest(struct Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    printf("%d",root->key);
}

void largest(struct Node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    printf("%d",root->key);
}

// Main function
int main() {
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();
    smallest(root);
    largest(root);
    return 0;
}