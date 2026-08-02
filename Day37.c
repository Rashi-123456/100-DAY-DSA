/* Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20 */
#include <stdio.h>
#include <string.h>
#define MAX 100000
int heap[MAX];
int size = 0;
void insert(int val) {
    int i = size++;
    heap[i] = val;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}
int deleteMin() {
    if (size == 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest == i)
            break;
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
    return min;
}
int peek() {
    if (size == 0)
        return -1;
    return heap[0];
}
int main() {
    int N, x;
    char op[10];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}