/* Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2 */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1)
        return NULL;
    struct Node* root = createNode(a[0]);
    struct Node* queue[n];
    int front = 0, rear = 0, i = 1;
    queue[rear++] = root;
    while (front < rear && i < n) {
        struct Node* cur = queue[front++];
        if (a[i] != -1) {
            cur->left = createNode(a[i]);
            queue[rear++] = cur->left;
        }
        i++;
        if (i < n && a[i] != -1) {
            cur->right = createNode(a[i]);
            queue[rear++] = cur->right;
        }
        i++;
    }
    return root;
}
struct Node* lca(struct Node* root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q)
        return root;
    struct Node* left = lca(root->left, p, q);
    struct Node* right = lca(root->right, p, q);
    if (left && right)
        return root;
    return left ? left : right;
}
int main() {
    int n, p, q;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);
    struct Node* root = buildTree(a, n);
    struct Node* result = lca(root, p, q);
    if (result)
        printf("LCA: %d\n", result->data);
    else
        printf("LCA not found\n");
    return 0;
}