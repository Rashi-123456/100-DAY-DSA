/* Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, 
the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], 
and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    long long sum;
    int freq;
    struct Node *next;
} Node;
#define SIZE 100003
Node *table[SIZE];
int hash(long long key) {
    long long h = key % SIZE;
    if (h < 0)
        h += SIZE;
    return (int)h;
}
int getFreq(long long sum) {
    int idx = hash(sum);
    Node *curr = table[idx];
    while (curr) {
        if (curr->sum == sum)
            return curr->freq;
        curr = curr->next;
    }
    return 0;
}
void insert(long long sum) {
    int idx = hash(sum);
    Node *curr = table[idx];
    while (curr) {
        if (curr->sum == sum) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->freq = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}
int main() {
    int n;
    scanf("%d", &n);
    long long prefixSum = 0;
    long long count = 0;
    insert(0); 
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        prefixSum += x;
        count += getFreq(prefixSum);
        insert(prefixSum);
    }
    printf("%lld", count);
    return 0;
}