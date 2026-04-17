#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(temp->vertex, adj, visited, stack, top);
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n], top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
