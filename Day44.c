/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1) return NULL;
    Node **q = malloc(n * sizeof(Node*));
    Node *root = malloc(sizeof(Node));
    root->data = a[0];
    root->left = root->right = NULL;
    int front = 0, rear = 0, i = 1;
    q[rear++] = root;
    while (front < rear && i < n) {
        Node *cur = q[front++];
        if (i < n && a[i] != -1) {
            cur->left = malloc(sizeof(Node));
            cur->left->data = a[i];
            cur->left->left = cur->left->right = NULL;
            q[rear++] = cur->left;
        }
        i++;
        if (i < n && a[i] != -1) {
            cur->right = malloc(sizeof(Node));
            cur->right->data = a[i];
            cur->right->left = cur->right->right = NULL;
            q[rear++] = cur->right;
        }
        i++;
    }
    free(q);
    return root;
}
void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = buildTree(a, n);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    free(a);
    return 0;
}