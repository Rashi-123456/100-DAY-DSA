/* Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    float value;
    struct Node *next;
} Node;
void insert(Node **head, float value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *curr = *head;
    while (curr->next != NULL && curr->next->value < value)
        curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));
    Node **buckets = (Node **)calloc(n, sizeof(Node *));
    printf("Enter %d real numbers in [0,1): ", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        insert(&buckets[index], arr[i]);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node *curr = buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->value;
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.3f ", arr[i]);

    free(arr);
    free(buckets);
    return 0;
}