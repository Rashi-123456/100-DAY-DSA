/* Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct{
    int u,v,w;
}Edge;
int main(){
    int n,m,src;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    Edge *edges=malloc(m*sizeof(Edge));
    printf("Enter edges (source destination weight):\n");
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    printf("Enter source vertex: ");
    scanf("%d",&src);
    int *dist=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=1;i<n;i++){
        int updated=0;
        for(int j=0;j<m;j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;
            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                updated=1;
            }
        }
        if(!updated)
            break;
    }
    for(int i=0;i<m;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
            printf("\nNEGATIVE CYCLE\n");
            free(edges);
            free(dist);
            return 0;
        }
    }
    printf("\nShortest distances from vertex %d:\n",src);
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX)
            printf("Vertex %d: INF\n",i);
        else
            printf("Vertex %d: %d\n",i,dist[i]);
    }
    free(edges);
    free(dist);
    return 0;
}