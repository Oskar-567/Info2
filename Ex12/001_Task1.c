#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define INF 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 9;
int numEdges = 14;

// Hilfsfunktion: Finde Knoten mit minimalem Schlüsselwert, der noch nicht im MST ist
int minKey(int key[], bool mstSet[]) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < numVertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim’s Algorithmus
int primMST() {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        totalWeight += graph[i][parent[i]];
    }
    return totalWeight;
}

int main() {
    // Initialisiere Matrix mit INF
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    // Beispiel-Kanten aus der Aufgabe
    int edges[14][3] = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 5, 4},
        {2, 8, 2},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };

    // Trage die Kanten in die Adjazenzmatrix ein
    for (int i = 0; i < numEdges; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        graph[from][to] = weight;
        graph[to][from] = weight; // ungerichtet
    }

    // Optional: Ausgabe der Adjazenzmatrix
    printf("Adjazenzmatrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == INF)
                printf("x ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Berechne MST
    int result = primMST();
    printf("The total weight of the MST is %d\n", result);

    return 0;
}