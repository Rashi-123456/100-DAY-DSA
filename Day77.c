/* Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED */
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
    dfs(1,n,graph,visited);
    int connected=1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            connected=0;
            break;
        }
    }
    if(connected)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");
    for(int i=0;i<=n;i++)
        free(graph[i]);
    free(graph);
    free(visited);
    return 0;
}