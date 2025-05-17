#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define MAX_EDGES 1000
#define INF 10000

// Kantendefinition
struct Edge {
    int dest;
    int weight;
};

// Graph mit Adjazenzliste (array-simuliert)
struct Graph {
    int num_vertices;
    struct Edge array[MAX_VERTICES][MAX_VERTICES]; // [Von][Liste von Kanten]
};

// SPFA Algorithmus
bool spfa(struct Graph* graph, int src, int dist[]) {
    bool inQueue[MAX_VERTICES] = { false };
    int count[MAX_VERTICES] = { 0 };
    int queue[MAX_VERTICES * MAX_VERTICES]; // einfache Warteschlange
    int front = 0, rear = 0;

    // Initialisierung
    for (int i = 0; i < graph->num_vertices; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    queue[rear++] = src;
    inQueue[src] = true;
    count[src]++;

    // Hauptschleife
    while (front != rear) {
        int u = queue[front++];
        inQueue[u] = false;

        int edge_idx = 0;
        while (graph->array[u][edge_idx].dest != -1) {
            int v = graph->array[u][edge_idx].dest;
            int weight = graph->array[u][edge_idx].weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;

                if (!inQueue[v]) {
                    queue[rear++] = v;
                    inQueue[v] = true;
                    count[v]++;

                    // Negative Zyklenprüfung
                    if (count[v] > graph->num_vertices - 1) {
                        return false; // negativer Zyklus erkannt
                    }
                }
            }
            edge_idx++;
        }
    }

    return true; // erfolgreich ohne Zyklus
}

// Beispielmain mit Eingabe aus Aufgabenstellung
int main() {
    struct Graph graph;
    graph.num_vertices = 5;

    // Initialisierung der Kantenliste
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph.array[i][j].dest = -1;
        }
    }

    // Kanten aus der Aufgabenstellung (kein negativer Zyklus)
    int edges[8][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 3},
        {1, 4, 2},
        {3, 1, 1},
        {3, 2, 5},   // für negativen Zyklus zu {2, 3, -5} ändern
        {4, 3, -3}
    };

    // Adjazenzliste aufbauen
    int edge_counters[MAX_VERTICES] = { 0 };
    for (int i = 0; i < 8; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        int idx = edge_counters[from]++;
        graph.array[from][idx].dest = to;
        graph.array[from][idx].weight = weight;
    }

    int dist[MAX_VERTICES];
    bool noNegativeCycle = spfa(&graph, 0, dist);

    if (noNegativeCycle) {
        printf("Shortest distances from vertex 0:\n");
        for (int i = 0; i < graph.num_vertices; i++) {
            if (dist[i] >= INF)
                printf("Vertex %d: unreachable\n", i);
            else
                printf("Vertex %d: %d\n", i, dist[i]);
        }
    } else {
        printf("Graph contains a negative weight cycle\n");
    }

    return 0;
}