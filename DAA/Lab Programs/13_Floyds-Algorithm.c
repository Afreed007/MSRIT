#include <stdio.h>

#define MAX 100
#define INF 99999

void floyd(int n, int dist[MAX][MAX]) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int n, i, j;
    int dist[MAX][MAX];

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF/no edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Distance from node %d to node %d: ", i, j);
            scanf("%d", &dist[i][j]);
        }
    }

    floyd(n, dist);

    printf("\nShortest distances between every pair of nodes:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
