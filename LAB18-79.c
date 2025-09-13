#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int idx=0;
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

int search(int postorder[],int pre,int l,int r){
    for(int i=l;i<=r;i++){
        if(postorder[i] == pre){
            return i;
        }
    }
    return -1;
}

// Build the tree
struct Node* createBST(int preorder[],int postorder[],int l,int r,int size) {
    if(idx>=size||l>r){
        return NULL;
    }
    struct Node *root = newNode(preorder[idx]);
    idx++;
    if(l==r||idx>=size){
        return root;
    }
    int i= search(postorder,preorder[idx],l,r);
    if(i!=-1){
        root->left = createBST(preorder,postorder,0,i,size);
        root->right = createBST(preorder,postorder,i+1,r-1,size);
    }
    return root;
}

void preordercheck(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preordercheck(root->left);
        preordercheck(root->right);
    }
}

void postordercheck(struct Node* root) {
    if (root != NULL) {
        postordercheck(root->left);
        postordercheck(root->right);
        printf("%d ", root->key);
    }
}
// Main function
int main() {
    int size=-1;
    int preorder[100];
    int postorder[100];
    printf("Build your binary tree enter preorder and postorder:\n");
    int val;
    while (scanf("%d", &val) && val != -1) {
        preorder[++size] = val;
    }
    size++; // Final size after reading
    printf("%d",size);
    while (scanf("%d", &val) && val != -1) {
        postorder[++size] = val;
    }
    struct Node* root = createBST(preorder,postorder,0,size,size);
    printf("preorder: ");
    preordercheck(root);
    printf("\npostorder: ");
    postordercheck(root);
    return 0;
}