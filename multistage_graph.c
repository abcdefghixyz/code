#include <stdio.h>
#define INF 9999999
#define V 6

int min(int x, int y) {
    return (x < y) ? x : y;
}

int shortestPath(int graph[V][V]) {
    int i,j,cost[V];
    cost[V-1] = 0; 

    for ( i = V - 2; i >= 0; i--) {
        cost[i] = INF;
        for ( j = i; j < V; j++) {
            if (graph[i][j] == INF) 
                continue;

            cost[i] = min(cost[i], graph[i][j] + cost[j]);
        }
    }

    return cost[0];
}

int main() {
    int graph[V][V] = {
        {INF, 1, 2, 5, INF, INF, },
        { INF, INF, 4, 11, INF, INF},
        { INF, INF, 9, 5, 16, INF},
        { INF, INF, INF, INF, 2, INF},
        { INF, INF, INF, INF, INF, 18},
        { INF, INF, INF, INF, INF, 13},
//        { INF, INF, INF, INF, INF, 2},
//        { INF, INF, INF, INF, INF, INF}
    };

    printf("The shortest path cost is %d\n", shortestPath(graph));
    return 0;
}


