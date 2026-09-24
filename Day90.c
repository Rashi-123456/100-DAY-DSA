/* Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. 
Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40. */
#include <stdio.h>
int canPaint(int boards[], int n, int k, long long maxTime) {
    int painters = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + boards[i] > maxTime) {
            painters++;
            sum = boards[i];
        } else {
            sum += boards[i];
        }
    }
    return painters <= k;
}
int main() {
    int n, k;
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);
    int boards[n];
    long long low = 0, high = 0;
    printf("Enter %d board lengths: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canPaint(boards, n, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    printf("Minimum time required: %lld\n", low);
    return 0;
}