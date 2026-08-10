/* Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int height(Node *root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n == 0 || a[0] == -1) {
        printf("0");
        free(a);
        return 0;
    }
    Node **queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    Node *root = createNode(a[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node *current = queue[front++];
        if (i < n && a[i] != -1) {
            current->left = createNode(a[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && a[i] != -1) {
            current->right = createNode(a[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    printf("%d", height(root));
    free(a);
    free(queue);
    return 0;
}