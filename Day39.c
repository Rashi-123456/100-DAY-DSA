/* Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30 */
#include <stdio.h>
#include <string.h>
#define MAX 100000
int heap[MAX];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int val) {
    int i = size++;
    heap[i] = val;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}
int peek() {
    if (size == 0)
        return -1;
    return heap[0];
}
int extractMin() {
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
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return min;
}
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }
    return 0;
}