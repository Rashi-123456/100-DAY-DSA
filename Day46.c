/* Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications */
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
        struct Node* current = queue[front++];
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
    return root;
}
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter level-order elements (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    struct Node* root = buildTree(a, n);
    printf("Level Order Traversal: ");
    levelOrder(root);
    return 0;
}