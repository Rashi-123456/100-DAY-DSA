/* Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node *next;
};
void addEdge(struct Node *adj[], int u, int v) {
    struct Node *a = malloc(sizeof(struct Node));
    a->vertex = v;
    a->next = adj[u];
    adj[u] = a;
    struct Node *b = malloc(sizeof(struct Node));
    b->vertex = u;
    b->next = adj[v];
    adj[v] = b;
}
int dfs(struct Node *adj[], int v, int parent, int visited[]) {
    visited[v] = 1;
    struct Node *temp = adj[v];
    while (temp != NULL) {
        int next = temp->vertex;
        if (!visited[next]) {
            if (dfs(adj, next, v, visited))
                return 1;
        } else if (next != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main() {
    int n, m, u, v;
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
    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, -1, visited)) {
                cycle = 1;
                break;
            }
        }
    }
    printf("\nCycle Detected: %s\n", cycle ? "YES" : "NO");
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