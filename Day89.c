/* Problem Statement
Given an array of integers where each element represents the number of pages in a book,
and m students, allocate books such that each student gets at least one book and the maximum number
 of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible). */
#include <stdio.h>
int canAllocate(int pages[], int n, int m, long long maxPages) {
    int students = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + pages[i] > maxPages) {
            students++;
            sum = pages[i];
        } else {
            sum += pages[i];
        }
    }
    return students <= m;
}
int main() {
    int n, m;
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);
    int pages[n];
    printf("Enter %d book page counts: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    if (m > n) {
        printf("Minimum maximum pages: -1\n");
        return 0;
    }
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > low)
            low = pages[i];
        high += pages[i];
    }
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canAllocate(pages, n, m, mid))
            high = mid;
        else
            low = mid + 1;
    }
    printf("Minimum maximum pages: %lld\n", low);
    return 0;
}