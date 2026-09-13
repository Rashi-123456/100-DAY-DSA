/* Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Edge{
    int to,weight;
    struct Edge *next;
}Edge;
typedef struct{
    int vertex;
    long long dist;
}Node;
typedef struct{
    Node *a;
    int size,capacity;
}Heap;
void swap(Node *a,Node *b){
    Node t=*a;
    *a=*b;
    *b=t;
}
void push(Heap *h,int v,long long d){
    if(h->size==h->capacity){
        h->capacity*=2;
        h->a=realloc(h->a,h->capacity*sizeof(Node));
    }
    int i=h->size++;
    h->a[i]=(Node){v,d};
    while(i>0){
        int p=(i-1)/2;
        if(h->a[p].dist<=h->a[i].dist)
            break;
        swap(&h->a[p],&h->a[i]);
        i=p;
    }
}
Node pop(Heap *h){
    Node res=h->a[0];
    h->a[0]=h->a[--h->size];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<h->size&&h->a[l].dist<h->a[s].dist)
            s=l;
        if(r<h->size&&h->a[r].dist<h->a[s].dist)
            s=r;
        if(s==i)
            break;
        swap(&h->a[i],&h->a[s]);
        i=s;
    }
    return res;
}
int main(){
    int n,m;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    Edge **graph=calloc(n+1,sizeof(Edge*));
    printf("Enter %d edges (u v w):\n",m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        Edge *e=malloc(sizeof(Edge));
        e->to=v;
        e->weight=w;
        e->next=graph[u];
        graph[u]=e;
        e=malloc(sizeof(Edge));
        e->to=u;
        e->weight=w;
        e->next=graph[v];
        graph[v]=e;
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d",&source);
    long long *dist=malloc((n+1)*sizeof(long long));
    for(int i=1;i<=n;i++)
        dist[i]=LLONG_MAX;
    dist[source]=0;
    Heap heap;
    heap.size=0;
    heap.capacity=16;
    heap.a=malloc(heap.capacity*sizeof(Node));
    push(&heap,source,0);
    while(heap.size){
        Node cur=pop(&heap);
        int u=cur.vertex;
        if(cur.dist!=dist[u])
            continue;
        for(Edge *e=graph[u];e;e=e->next){
            int v=e->to;
            long long nd=cur.dist+e->weight;
            if(nd<dist[v]){
                dist[v]=nd;
                push(&heap,v,nd);
            }
        }
    }
    printf("Shortest distances from source %d:\n",source);
    for(int i=1;i<=n;i++){
        if(dist[i]==LLONG_MAX)
            printf("Vertex %d: INF\n",i);
        else
            printf("Vertex %d: %lld\n",i,dist[i]);
    }
    for(int i=1;i<=n;i++){
        Edge *e=graph[i];
        while(e){
            Edge *temp=e;
            e=e->next;
            free(temp);
        }
    }
    free(graph);
    free(dist);
    free(heap.a);
    return 0;
}