/* Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times. */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Meeting;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}
void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest == index)
            break;
        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}
int pop(int heap[], int *size) {
    int result = heap[0];
    (*size)--;
    if (*size > 0) {
        heap[0] = heap[*size];
        heapifyDown(heap, *size, 0);
    }
    return result;
}
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}
int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0)
        return 0;
    qsort(meetings, n, sizeof(Meeting), compare);
    int *heap = malloc(n * sizeof(int));
    int heapSize = 0;
    int maxRooms = 0;
    for (int i = 0; i < n; i++) {
        while (heapSize > 0 && heap[0] <= meetings[i].start)
            pop(heap, &heapSize);
        push(heap, &heapSize, meetings[i].end);
        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }
    free(heap);
    return maxRooms;
}
int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    Meeting *meetings = malloc(n * sizeof(Meeting));
    printf("Enter start and end time for each meeting:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    printf("Minimum rooms required: %d\n", minMeetingRooms(meetings, n));
    free(meetings);
    return 0;
}