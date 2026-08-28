/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node *next;
};
void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    if (adj[u] == NULL) {
        adj[u] = newNode;
    } else {
        struct Node *temp = adj[u];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void dfs(struct Node *adj[], int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    struct Node *temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(adj, temp->vertex, visited);
        temp = temp->next;
    }
}
int main() {
    int n, m, u, v, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    struct Node *adj[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("\nDFS Traversal: ");
    dfs(adj, s, visited);
    printf("\n");
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