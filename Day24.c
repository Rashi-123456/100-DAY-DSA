/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
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
    int n, key, x;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node *newNode = createNode(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &key);
    struct Node *curr = head, *prev = NULL;
    while (curr != NULL) {
        if (curr->data == key) {
            if (prev == NULL)
                head = curr->next;      
            else
                prev->next = curr->next;
            free(curr);
            break;                      
        }
        prev = curr;
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(" ");
        curr = curr->next;
    }
    return 0;
}