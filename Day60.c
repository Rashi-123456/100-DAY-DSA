/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter level-order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int valid = 1;
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && a[i] > a[left]) {
            valid = 0;
            break;
        }
        if (right < n && a[i] > a[right]) {
            valid = 0;
            break;
        }
    }
    printf("Output: %s\n", valid ? "YES" : "NO");
    free(a);
    return 0;
}