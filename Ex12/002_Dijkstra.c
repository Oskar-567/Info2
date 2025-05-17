#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define INF 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 5;
int numEdges = 10;

// Funktion zur Auswahl des nächsten Knotens mit minimaler Distanz
int minDistance(int dist[], bool visited[]) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra-Algorithmus
void dijkstra(int src) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break; // keine erreichbaren Knoten mehr

        visited[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Ausgabe
    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < numVertices; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    // Graph initialisieren
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = INF;

    // Kanten aus Aufgabenstellung
    int edges[10][3] = {
        {0, 1, 10},
        {0, 2, 5},
        {1, 2, 2},
        {1, 3, 1},
        {2, 1, 3},
        {2, 3, 9},
        {2, 4, 2},
        {3, 4, 4},
        {4, 0, 7},
        {4, 3, 6}
    };

    // Kanten in Adjazenzmatrix eintragen
    for (int i = 0; i < numEdges; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        graph[from][to] = weight; // gerichteter Graph
    }

    // Dijkstra aufrufen
    dijkstra(0);

    return 0;
}