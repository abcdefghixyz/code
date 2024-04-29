
#include <stdio.h>

#define INF 99999
#define V 5

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
	int i,j;
    printf("Shortest distances between every pair of vertices:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {{0, 5, INF,INF, 10},
                       {2,INF, 0, 3, INF},
                       {4,3, INF, 0, 1},
                       {INF, INF, INF,INF, 0},
					   {INF,3,0,INF,1}
					   };

    floydWarshall(graph);
    return 0;
}

