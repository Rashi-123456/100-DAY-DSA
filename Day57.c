/* Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
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
    Node* queue[n];
    int front = 0, rear = 0, i = 1;
    queue[rear++] = root;
    while (front < rear && i < n) {
        Node* cur = queue[front++];
        if (i < n && a[i] != -1) {
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
void mirror(Node* root) {
    if (root == NULL)
        return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    mirror(root);
    printf("Inorder traversal of mirrored tree: ");
    inorder(root);
    printf("\n");
    return 0;
}