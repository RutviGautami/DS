#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive helper to check mirror symmetry
int isMirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    return (a->key == b->key)
           && isMirror(a->left, b->right)
           && isMirror(a->right, b->left);
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

// Function for interactive tree creation
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

int main() {
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();

    if (isSymmetric(root))
        printf("Given tree is symmetric\n");
    else
        printf("Given tree is not symmetric\n");

    return 0;
}
