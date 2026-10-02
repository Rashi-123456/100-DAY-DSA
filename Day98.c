/* Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous. */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Interval;
int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    if (x->start != y->start)
        return x->start - y->start;
    return x->end - y->end;
}
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    Interval *arr = malloc(n * sizeof(Interval));
    printf("Enter intervals:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);
    qsort(arr, n, sizeof(Interval), compare);
    Interval *result = malloc(n * sizeof(Interval));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0 || arr[i].start > result[count - 1].end) {
            result[count++] = arr[i];
        } else {
            if (arr[i].end > result[count - 1].end)
                result[count - 1].end = arr[i].end;
        }
    }
    printf("Merged intervals:\n");
    for (int i = 0; i < count; i++)
        printf("[%d, %d]\n", result[i].start, result[i].end);
    free(arr);
    free(result);
    return 0;
}