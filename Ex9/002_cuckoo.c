#include <stdio.h>
#include <stdlib.h>

#define M1 10 // Größe der ersten Hash-Tabelle
#define M2 10 // Größe der zweiten Hash-Tabelle

// Hash-Tabellen
int H1[M1]; // Erste Hash-Tabelle
int H2[M2]; // Zweite Hash-Tabelle

// Initialisieren der Tabellen
void initialize_tables() {
    for (int i = 0; i < M1; i++) {
        H1[i] = -1; // -1 bedeutet leer
    }
    for (int i = 0; i < M2; i++) {
        H2[i] = -1; // -1 bedeutet leer
    }
}

// h1 - Hash-Funktion für H1
int h1(int k) {
    return k % M1;
}

// h2 - Hash-Funktion für H2
int h2(int k) {
    return (k / 10) % M2; // Beispiel: Teilen durch 10, dann mod M2
}

// Funktion für das Einfügen von Elementen in die Tabellen
void cuckoo_insert(int k) {
    int key = k;
    int temp, pos1, pos2;

    // Beginne in H1
    while (1) {
        // Versuche, das Element in H1 zu setzen
        pos1 = h1(key);

        // Wenn der Platz in H1 leer ist oder das Element der gleiche Schlüssel ist,
        // können wir das Element dort einfügen
        if (H1[pos1] == -1) {
            H1[pos1] = key;
            return;
        }

        // Wenn der Platz bereits belegt ist, tausche das Element aus
        temp = H1[pos1];
        H1[pos1] = key;
        key = temp;

        // Versuche dann das gekickte Element in H2 zu setzen
        pos2 = h2(key);

        // Wenn der Platz in H2 leer ist, füge das Element dort ein
        if (H2[pos2] == -1) {
            H2[pos2] = key;
            return;
        }

        // Wenn der Platz bereits belegt ist, tausche das Element aus
        temp = H2[pos2];
        H2[pos2] = key;
        key = temp;
    }
}

int cuckoo_search(int k) {
    int pos1 = h1(k);
    int pos2 = h2(k);

    // Überprüfe, ob das Element in der ersten Hash-Tabelle (H1) vorhanden ist
    if (H1[pos1] == k) {
        return 1; // Element gefunden in H1
    }

    // Überprüfe, ob das Element in der zweiten Hash-Tabelle (H2) vorhanden ist
    if (H2[pos2] == k) {
        return 1; // Element gefunden in H2
    }

    return 0; // Element nicht gefunden
}

// Ausgabe der Tabellen
void print_tables() {
    printf("H1: ");
    for (int i = 0; i < M1; i++) {
        printf("%d ", H1[i]);
    }
    printf("\n");

    printf("H2: ");
    for (int i = 0; i < M2; i++) {
        printf("%d ", H2[i]);
    }
    printf("\n");
}

int main() {
    int elements[] = {1,2,3,4,11,14};
    int size = sizeof(elements) / sizeof(elements[0]);

    // Initialisiere die Hash-Tabellen
    initialize_tables();

    // Füge jedes Element mit Cuckoo Hashing ein
    for (int i = 0; i < size; i++) {
        cuckoo_insert(elements[i]);
    }

    // Ausgabe der Ergebnisse
    print_tables();

    printf("Search for 1: %s\n", cuckoo_search(1) ? "Found" : "Not Found");
    printf("Search for 4: %s\n", cuckoo_search(4) ? "Found" : "Not Found");
    printf("Search for 201: %s\n", cuckoo_search(201) ? "Found" : "Not Found");

    return 0;
}