/* Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps */
#include<stdio.h>
#include<string.h>
int main(){
    int m,n;
    printf("Enter table size: ");
    scanf("%d",&m);
    printf("Enter number of operations: ");
    scanf("%d",&n);
    int table[m];
    for(int i=0;i<m;i++)
        table[i]=-1;
    char op[10];
    int key;
    printf("Enter operations:\n");
    for(int j=0;j<n;j++){
        scanf("%s%d",op,&key);
        int h=((key%m)+m)%m;
        if(strcmp(op,"INSERT")==0){
            for(int i=0;i<m;i++){
                int pos=(h+(i*i)%m)%m;
                if(table[pos]==-1){
                    table[pos]=key;
                    break;
                }
            }
        }
        else if(strcmp(op,"SEARCH")==0){
            int found=0;
            for(int i=0;i<m;i++){
                int pos=(h+(i*i)%m)%m;
                if(table[pos]==-1)
                    break;
                if(table[pos]==key){
                    found=1;
                    break;
                }
            }
            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    return 0;
} 