/* Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
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
void dfs(struct Node *adj[], int v, int visited[], int stack[], int *top) {
    visited[v] = 1;
    struct Node *temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(adj, temp->vertex, visited, stack, top);
        temp = temp->next;
    }
    stack[++(*top)] = v;
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
    int top = -1;
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(adj, i, visited, stack, &top);
    }
    printf("\nTopological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
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