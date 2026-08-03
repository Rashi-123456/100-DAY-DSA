/* Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;
void init(Deque *dq) {
    dq->front = MAX / 2;
    dq->rear = MAX / 2 - 1;
}
int empty(Deque *dq) {
    return dq->front > dq->rear;
}
int size(Deque *dq) {
    if (empty(dq))
        return 0;
    return dq->rear - dq->front + 1;
}
void push_front(Deque *dq, int x) {
    dq->arr[--dq->front] = x;
}
void push_back(Deque *dq, int x) {
    dq->arr[++dq->rear] = x;
}
void pop_front(Deque *dq) {
    if (!empty(dq))
        dq->front++;
}
void pop_back(Deque *dq) {
    if (!empty(dq))
        dq->rear--;
}
int front(Deque *dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->front];
}
int back(Deque *dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->rear];
}
void clear(Deque *dq) {
    dq->front = MAX / 2;
    dq->rear = MAX / 2 - 1;
}
void reverse(Deque *dq) {
    int i = dq->front, j = dq->rear;
    while (i < j) {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;
        i++;
        j--;
    }
}
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void sortDeque(Deque *dq) {
    if (!empty(dq))
        qsort(&dq->arr[dq->front], size(dq), sizeof(int), cmp);
}
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = dq->front; i <= dq->rear; i++)
        printf("%d ", dq->arr[i]);
    printf("\n");
}
int main() {
    Deque dq;
    init(&dq);
    int q;
    scanf("%d", &q);
    while (q--) {
        int op, x;
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d", &x);
                push_front(&dq, x);
                break;
            case 2:
                scanf("%d", &x);
                push_back(&dq, x);
                break;
            case 3:
                pop_front(&dq);
                break;
            case 4:
                pop_back(&dq);
                break;
            case 5:
                if (!empty(&dq))
                    printf("%d\n", front(&dq));
                else
                    printf("Deque is empty\n");
                break;
            case 6:
                if (!empty(&dq))
                    printf("%d\n", back(&dq));
                else
                    printf("Deque is empty\n");
                break;
            case 7:
                printf("%s\n", empty(&dq) ? "Yes" : "No");
                break;
            case 8:
                printf("%d\n", size(&dq));
                break;
            case 9:
                clear(&dq);
                break;
            case 10:
                reverse(&dq);
                break;
            case 11:
                sortDeque(&dq);
                break;
            case 12:
                display(&dq);
                break;
            default:
                printf("Invalid Operation\n");
        }
    }
    return 0;
}