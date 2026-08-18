/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance
are printed together. */
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
void verticalOrder(struct Node* root, int hd, int *minHD, int *maxHD,
                   int **columns, int *sizes) {
    if (root == NULL)
        return;
    if (hd < *minHD)
        *minHD = hd;
    if (hd > *maxHD)
        *maxHD = hd;
    int index = hd + 10000;
    columns[index][sizes[index]++] = root->data;
    verticalOrder(root->left, hd - 1, minHD, maxHD, columns, sizes);
    verticalOrder(root->right, hd + 1, minHD, maxHD, columns, sizes);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    struct Node* root = buildTree(a, n);
    if (root == NULL)
        return 0;
    int size = 20001;
    int **columns = (int**)malloc(size * sizeof(int*));
    int *sizes = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        columns[i] = (int*)malloc(n * sizeof(int));
    int minHD = 0, maxHD = 0;
    verticalOrder(root, 0, &minHD, &maxHD, columns, sizes);
    printf("Vertical Order Traversal:\n");
    for (int hd = minHD; hd <= maxHD; hd++) {
        int index = hd + 10000;
        for (int j = 0; j < sizes[index]; j++)
            printf("%d ", columns[index][j]);
        printf("\n");
    }
    return 0;
}