/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node *next;
};
void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
void display(struct Node *adj[], int n) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node *temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int n, m, u, v, directed;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    struct Node *adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter 1 for directed graph, 0 for undirected graph: ");
    scanf("%d", &directed);
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        if (!directed)
            addEdge(adj, v, u);
    }
    display(adj, n);
    for (int i = 0; i < n; i++) {
        struct Node *temp = adj[i];
        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    return 0;
}