/* Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j]. */
#include <stdio.h>
#include <stdlib.h>
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv;
}
long long mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right)
        return 0;
    int mid = left + (right - left) / 2;
    long long inv = 0;
    inv += mergeSort(arr, temp, left, mid);
    inv += mergeSort(arr, temp, mid + 1, right);
    inv += merge(arr, temp, left, mid, right);
    return inv;
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    long long inversions = mergeSort(arr, temp, 0, n - 1);
    printf("Number of inversions: %lld\n", inversions);
    free(arr);
    free(temp);
    return 0;
}