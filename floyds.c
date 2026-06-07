#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, a[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            if (i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    // Floyd's Algorithm [i->k->j or i->j]
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] != INF && a[k][j] != INF &&
                    a[i][k] + a[k][j] < a[i][j]) {// i->k + k->j < i->j

                    a[i][j] = a[i][k] + a[k][j];// IF SMALLER CHANGE VALUE
                }
            }
        }
    }

    printf("\nShortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
