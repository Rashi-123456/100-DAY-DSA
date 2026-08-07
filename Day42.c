/* Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10 */
#include <stdio.h>
#define MAX 100000
int queue[MAX];
int stack[MAX];
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }
    int top = -1;
    for (int i = 0; i < N; i++) {
        stack[++top] = queue[i];
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    return 0;
}