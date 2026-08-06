/* Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node *front = NULL, *rear = NULL;
void enqueue(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
int dequeue() {
    if (front == NULL)
        return -1;
    Node *temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return value;
}
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char operation[20];
        scanf("%s", operation);
        if (strcmp(operation, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(operation, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}