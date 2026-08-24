/* Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* buildTree(int inorder[], int postorder[], int *postIndex, int left, int right) {
    if (left > right)
        return NULL;
    Node *root = createNode(postorder[(*postIndex)--]);
    int pos = left;
    while (inorder[pos] != root->data)
        pos++;
    root->right = buildTree(inorder, postorder, postIndex, pos + 1, right);
    root->left = buildTree(inorder, postorder, postIndex, left, pos - 1);
    return root;
}
void preorder(Node *root, int *first) {
    if (root == NULL)
        return;
    if (!(*first))
        printf(" ");
    printf("%d", root->data);
    *first = 0;
    preorder(root->left, first);
    preorder(root->right, first);
}
void freeTree(Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *inorder = (int*)malloc(n * sizeof(int));
    int *postorder = (int*)malloc(n * sizeof(int));
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    int postIndex = n - 1;
    Node *root = buildTree(inorder, postorder, &postIndex, 0, n - 1);
    printf("Preorder traversal: ");
    int first = 1;
    preorder(root, &first);
    printf("\n");
    freeTree(root);
    free(inorder);
    free(postorder);
    return 0;
}