/* Problem: Implement Selection Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}