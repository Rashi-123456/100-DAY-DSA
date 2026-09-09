/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray. */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    long long sum;
    int index;
    struct Node *next;
}Node;
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int size=2*n+1;
    Node **table=calloc(size,sizeof(Node*));
    long long sum=0;
    int maxLen=0;
    Node *node=malloc(sizeof(Node));
    node->sum=0;
    node->index=0;
    node->next=NULL;
    table[0]=node;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int key=(int)((sum%size+size)%size);
        Node *cur=table[key];
        int found=0;
        while(cur){
            if(cur->sum==sum){
                int len=i+1-cur->index;
                if(len>maxLen)
                    maxLen=len;
                found=1;
                break;
            }
            cur=cur->next;
        }
        if(!found){
            Node *newNode=malloc(sizeof(Node));
            newNode->sum=sum;
            newNode->index=i+1;
            newNode->next=table[key];
            table[key]=newNode;
        }
    }
    printf("Length of longest zero-sum subarray: %d",maxLen);
    for(int i=0;i<size;i++){
        Node *cur=table[i];
        while(cur){
            Node *temp=cur;
            cur=cur->next;
            free(temp);
        }
    }
    free(table);
    free(arr);
    return 0;
}