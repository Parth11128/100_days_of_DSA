#include <stdio.h>
#define MAX 100
#define INF 999999

int n, m;
int graph[MAX][MAX];
int selected[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        selected[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    selected[1] = 1;
    int edges = 0, total = 0;

    while (edges < n - 1) {
        int x = 0, y = 0;
        int min_weight = INF;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j] < min_weight) {
                        min_weight = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        total += graph[x][y];
        edges++;
    }

    printf("%d\n", total);

    return 0;
}
