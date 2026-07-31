/* Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front.
 Display from front to rear. */
#include <stdio.h>
#define MAX 1000
int main() {
    int n;
    scanf("%d", &n);
    int queue[MAX];
    int front = 0, rear = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }
    while (front <= rear) {
        printf("%d", queue[front]);
        if (front < rear)
            printf(" ");
        front++;
    }
    return 0;
}