/* Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    char **names=malloc(n*sizeof(char*));
    int *count=calloc(n,sizeof(int));
    int size=0;
    for(int i=0;i<n;i++){
        char temp[101];
        scanf("%s",temp);
        int found=-1;
        for(int j=0;j<size;j++){
            if(strcmp(names[j],temp)==0){
                found=j;
                break;
            }
        }
        if(found!=-1)
            count[found]++;
        else{
            names[size]=malloc((strlen(temp)+1)*sizeof(char));
            strcpy(names[size],temp);
            count[size++]=1;
        }
    }
    int winner=0;
    for(int i=1;i<size;i++){
        if(count[i]>count[winner]||(count[i]==count[winner]&&strcmp(names[i],names[winner])<0))
            winner=i;
    }
    printf("%s %d",names[winner],count[winner]);
    for(int i=0;i<size;i++)
        free(names[i]);
    free(names);
    free(count);
    return 0;
}