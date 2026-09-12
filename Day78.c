/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2) */
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000
int main(){
    int n,m;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    int **graph=malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++){
        graph[i]=malloc((n+1)*sizeof(int));
        for(int j=0;j<=n;j++)
            graph[i][j]=INF;
    }
    printf("Enter %d edges (u v w):\n",m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }
    int *key=malloc((n+1)*sizeof(int));
    int *visited=calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++)
        key[i]=INF;
    key[1]=0;
    long long mst=0;
    for(int count=0;count<n;count++){
        int u=-1;
        for(int i=1;i<=n;i++){
            if(!visited[i]&&(u==-1||key[i]<key[u]))
                u=i;
        }
        visited[u]=1;
        mst+=key[u];
        for(int v=1;v<=n;v++){
            if(!visited[v]&&graph[u][v]<key[v])
                key[v]=graph[u][v];
        }
    }
    printf("Total weight of MST: %lld",mst);
    for(int i=0;i<=n;i++)
        free(graph[i]);
    free(graph);
    free(key);
    free(visited);
    return 0;
}