#include <stdio.h>
#include <stdlib.h>

#define INF 99999

struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};

void printSolution(int dist[], int n) {
	int i;
    printf("Vertex   Distance from Source\n");
    for ( i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int i,j;
    for (i = 0; i < V; ++i)
        dist[i] = INF;
    dist[src] = 0;

    for ( i = 1; i <= V - 1; ++i) {
        for (j = 0; j < E; ++j) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for ( i = 0; i < E; ++i) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printSolution(dist, V);
}

int main() {
    int V,i, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    printf("Enter the details of each edge (source, destination, weight):\n");
    for (i = 0; i < E; ++i) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    bellmanFord(graph, src);
    free(graph->edge);
    free(graph);

    return 0;
}
//input check 


