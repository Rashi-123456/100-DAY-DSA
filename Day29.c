/* Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, 
update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    int n, k;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node *newNode = createNode(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &k);
    if (head == NULL || head->next == NULL || k == 0) {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        return 0;
    }
    k %= n;
    if (k == 0) {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        return 0;
    }
    tail->next = head;          
    int steps = n - k;
    struct Node *curr = head;
    for (int i = 1; i < steps; i++)
        curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}