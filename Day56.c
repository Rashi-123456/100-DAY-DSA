/* Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1)
        return NULL;
    Node* root = createNode(a[0]);
    Node* q[n];
    int front = 0, rear = 0, i = 1;
    q[rear++] = root;
    while (front < rear && i < n) {
        Node* cur = q[front++];
        if (i < n && a[i] != -1) {
            cur->left = createNode(a[i]);
            q[rear++] = cur->left;
        }
        i++;
        if (i < n && a[i] != -1) {
            cur->right = createNode(a[i]);
            q[rear++] = cur->right;
        }
        i++;
    }
    return root;
}
int isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    return a->data == b->data &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}
int isSymmetric(Node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node* root = buildTree(a, n);
    printf("Output: %s\n", isSymmetric(root) ? "YES" : "NO");
    return 0;
}