/* Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output. */
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, max = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d non-negative integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    int *freq = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (int i = 1; i <= max; i++)
        freq[i] += freq[i - 1];
    int *output = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
        output[--freq[arr[i]]] = arr[i];
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);
    free(arr);
    free(freq);
    free(output);
    return 0;
}