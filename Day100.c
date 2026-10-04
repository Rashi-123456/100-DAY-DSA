/* Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT) */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int index;
} Pair;
void merge(Pair a[], Pair temp[], int count[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, smaller = 0;
    while (i <= mid && j <= right) {
        if (a[j].value < a[i].value) {
            temp[k++] = a[j++];
            smaller++;
        } else {
            count[a[i].index] += smaller;
            temp[k++] = a[i++];
        }
    }
    while (i <= mid) {
        count[a[i].index] += smaller;
        temp[k++] = a[i++];
    }
    while (j <= right)
        temp[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = temp[i];
}
void mergeSort(Pair a[], Pair temp[], int count[], int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(a, temp, count, left, mid);
    mergeSort(a, temp, count, mid + 1, right);
    merge(a, temp, count, left, mid, right);
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *count = calloc(n, sizeof(int));
    Pair *a = malloc(n * sizeof(Pair));
    Pair *temp = malloc(n * sizeof(Pair));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].value);
        a[i].index = i;
    }
    mergeSort(a, temp, count, 0, n - 1);
    printf("Count of smaller elements on right: ");
    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);
    printf("\n");
    free(a);
    free(temp);
    free(count);
    return 0;
}