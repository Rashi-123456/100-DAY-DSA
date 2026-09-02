/* Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
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
int main() {
    int n, m, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    struct Node *adj[n];
    int indegree[n];
    int queue[n];
    int order[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }
    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }
    int count = 0;
    while (front < rear) {
        int node = queue[front++];
        order[count++] = node;
        struct Node *temp = adj[node];
        while (temp != NULL) {
            int next = temp->vertex;
            indegree[next]--;
            if (indegree[next] == 0)
                queue[rear++] = next;
            temp = temp->next;
        }
    }
    if (count != n) {
        printf("\nTopological ordering is not possible (cycle exists).\n");
    } else {
        printf("\nTopological Order: ");
        for (int i = 0; i < n; i++)
            printf("%d ", order[i]);
        printf("\n");
    }
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