/* Problem: Implement Binary Search Iterative - Implement the algorithm.

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
12 22 25 34 64 */
#include <stdio.h>
int main(){
    int n,target;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d sorted elements: ",n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter target: ");
    scanf("%d",&target);
    int low=0,high=n-1,index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==target){
            index=mid;
            break;
        }
        if(a[mid]>target)
            low=mid+1;
        else
            high=mid-1;
    }
    if(index!=-1)
        printf("Element found at index: %d\n",index);
    else
        printf("Element not found\n");
    return 0;
}