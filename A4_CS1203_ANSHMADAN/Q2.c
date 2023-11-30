//The code for q1 wont always work in a directed graph as we have to ensure the directed nature of the graph
//In a directed graph, Path from node A to B does not indicate a path from node B to A
//In the below directed graph code, we have changed the startign index from i=1 to i=0 to ensure that all vertices except 0 are considered for paths and distances
//There is also an additional if statement to exclude source vertex from being printed

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

void printSolution(int dist[], int parent[]) {
    int src = 0;
    printf("Vertex \t\t Distance from Source \t Path\n");
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("%d -> %d \t\t %d \t\t\t\t %d ", src, i, dist[i], src);
            printPath(parent, i);
            printf("\n");
        }
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 0, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 0, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 0, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}
