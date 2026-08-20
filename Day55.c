/* Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
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
void rightView(Node* root, int n) {
    if (root == NULL)
        return;
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Node* cur = queue[front++];
            if (i == size - 1)
                printf("%d ", cur->data);
            if (cur->left != NULL)
                queue[rear++] = cur->left;
            if (cur->right != NULL)
                queue[rear++] = cur->right;
        }
    }
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
    printf("Right View: ");
    rightView(root, n);
    printf("\n");
    return 0;
}