#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = malloc(sizeof(*node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

bool isIdentical(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->data == t2->data)
        && isIdentical(t1->left, t2->left)
        && isIdentical(t1->right, t2->right);
}

struct Node* buildTree(const char* prompt) {
    printf("%s Enter node value (or -1 for none): ", prompt);
    int val;
    if (scanf("%d", &val) != 1 || val == -1) return NULL;
    struct Node* root = newNode(val);
    root->left = buildTree(" Left child of this node:");
    root->right = buildTree(" Right child of this node:");
    return root;
}

int main() {
    printf("Build Tree 1:\n");
    struct Node* tree1 = buildTree("");
    printf("\nBuild Tree 2:\n");
    struct Node* tree2 = buildTree("");

    if (isIdentical(tree1, tree2))
        printf("\nGiven trees are identical\n");
    else
        printf("\nGiven trees are not identical\n");

    return 0;
}
