/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1)
        return NULL;
    Node* root = createNode(a[0]);
    Node** queue = malloc(n * sizeof(Node*));
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
    free(queue);
    return root;
}
void zigzag(Node* root, int n) {
    if (root == NULL)
        return;
    Node** queue = malloc(n * sizeof(Node*));
    int* level = malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int leftToRight = 1;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Node* cur = queue[front++];
            int pos = leftToRight ? i : size - 1 - i;
            level[pos] = cur->data;
            if (cur->left)
                queue[rear++] = cur->left;
            if (cur->right)
                queue[rear++] = cur->right;
        }
        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);
        leftToRight = !leftToRight;
    }
    free(queue);
    free(level);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int* a = malloc(n * sizeof(int));
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node* root = buildTree(a, n);
    printf("Zigzag Traversal: ");
    zigzag(root, n);
    printf("\n");
    free(a);
    return 0;
}