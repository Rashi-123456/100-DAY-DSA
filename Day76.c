/* Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>
#include <stdlib.h>
void dfs(int u,int n,int **graph,int *visited){
    visited[u]=1;
    for(int v=1;v<=n;v++){
        if(graph[u][v]&&!visited[v])
            dfs(v,n,graph,visited);
    }
}
int main(){
    int n,m;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    int **graph=malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++)
        graph[i]=calloc(n+1,sizeof(int));
    printf("Enter %d edges:\n",m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u][v]=graph[v][u]=1;
    }
    int *visited=calloc(n+1,sizeof(int));
    int components=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components++;
            dfs(i,n,graph,visited);
        }
    }
    printf("Number of connected components: %d",components);
    for(int i=0;i<=n;i++)
        free(graph[i]);
    free(graph);
    free(visited);
    return 0;
}