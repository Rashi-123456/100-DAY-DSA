/* Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct{
    int v,w;
}Edge;
typedef struct{
    int v,d;
}Node;
void swap(Node *a,Node *b){
    Node t=*a;
    *a=*b;
    *b=t;
}
void push(Node heap[],int *size,Node x){
    int i=(*size)++;
    heap[i]=x;
    while(i>0){
        int p=(i-1)/2;
        if(heap[p].d<=heap[i].d)break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}
Node pop(Node heap[],int *size){
    Node root=heap[0];
    heap[0]=heap[--(*size)];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<*size&&heap[l].d<heap[s].d)s=l;
        if(r<*size&&heap[r].d<heap[s].d)s=r;
        if(s==i)break;
        swap(&heap[i],&heap[s]);
        i=s;
    }
    return root;
}
int main(){
    int n,m,src;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    Edge **graph=malloc(n*sizeof(Edge*));
    int *deg=calloc(n,sizeof(int));
    int *u=malloc(m*sizeof(int));
    int *v=malloc(m*sizeof(int));
    int *w=malloc(m*sizeof(int));
    printf("Enter edges (source destination weight):\n");
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        deg[u[i]]++;
    }
    for(int i=0;i<n;i++)
        graph[i]=malloc(deg[i]*sizeof(Edge));
    int *idx=calloc(n,sizeof(int));
    for(int i=0;i<m;i++)
        graph[u[i]][idx[u[i]]++]=(Edge){v[i],w[i]};
    printf("Enter source vertex: ");
    scanf("%d",&src);
    int *dist=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    Node *heap=malloc((m+n+1)*sizeof(Node));
    int size=0;
    push(heap,&size,(Node){src,0});
    while(size){
        Node cur=pop(heap,&size);
        int u=cur.v;
        if(cur.d!=dist[u])
            continue;
        for(int i=0;i<deg[u];i++){
            int v=graph[u][i].v;
            int w=graph[u][i].w;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                push(heap,&size,(Node){v,dist[v]});
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n",src);
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX)
            printf("Vertex %d: INF\n",i);
        else
            printf("Vertex %d: %d\n",i,dist[i]);
    }
    return 0;
}