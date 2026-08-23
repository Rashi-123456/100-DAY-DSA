/* Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* build(int pre[], int in[], int *idx, int l, int r) {
    if (l > r) return NULL;
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = pre[(*idx)++];
    root->left = root->right = NULL;
    int pos = l;
    while (in[pos] != root->data)
        pos++;
    root->left = build(pre, in, idx, l, pos - 1);
    root->right = build(pre, in, idx, pos + 1, r);
    return root;
}
void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *pre = (int*)malloc(n * sizeof(int));
    int *in = (int*)malloc(n * sizeof(int));
    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    int idx = 0;
    Node *root = build(pre, in, &idx, 0, n - 1);
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    free(pre);
    free(in);
    return 0;
}