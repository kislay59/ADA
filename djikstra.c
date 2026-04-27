#include <stdio.h>
#define MAX 100
#define INF 99999

int minDistance(int dist[], int visited[], int n) {
    int min = INF, u = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int a[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX], parent[MAX];

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && a[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + a[u][v] < dist[v]) {

                dist[v] = dist[u] + a[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}

int main() {
    int n, a[MAX][MAX], source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(a, n, source);

    return 0;
}
