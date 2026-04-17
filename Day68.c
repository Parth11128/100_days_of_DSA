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

int queue[1000], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0)
                enqueue(temp->vertex);
            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle detected");

    return 0;
}
