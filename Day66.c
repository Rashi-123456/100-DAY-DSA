/* Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node *next;
};
void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
int dfs(struct Node *adj[], int v, int visited[], int stack[]) {
    visited[v] = 1;
    stack[v] = 1;
    struct Node *temp = adj[v];
    while (temp != NULL) {
        int next = temp->vertex;
        if (!visited[next]) {
            if (dfs(adj, next, visited, stack))
                return 1;
        } else if (stack[next]) {
            return 1;
        }
        temp = temp->next;
    }
    stack[v] = 0;
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
    int stack[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        stack[i] = 0;
    }
    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, visited, stack)) {
                cycle = 1;
                break;
            }
        }
    }
    printf("\nCycle Exists: %s\n", cycle ? "YES" : "NO");
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