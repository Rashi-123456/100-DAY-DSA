/* Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
int main() {
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node* root = NULL;
    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter value to search: ");
    scanf("%d", &key);
    if (search(root, key) != NULL)
        printf("Value %d found in the BST.\n", key);
    else
        printf("Value %d not found in the BST.\n", key);
    return 0;
}