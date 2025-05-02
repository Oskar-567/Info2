#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Linear Hashing un Double Hashing werden mit festen Arrays gemacht. Für HTinsert, HTsearch, HTdelete wird dann mit einem Pointer HTp auf das Struct elem gearbeitet um dann die elemente als deletet flaggen zu können.


int Array[] = {1,9, 101, 109, 115, 112, 203, 762, 362, 999, 1053, 473, 873, 82};
int sizeA = sizeof(Array)/sizeof(Array[0]);

//Double Hashing
int m1;
int m2;          //should be neares smaller prime to m1
int *HTdoub;

//Linear Hashing
// int m = sizeA*2;     m == m1;
int *HTlin;


struct elem {
    int key;
    int status;     //0: OCCupied, -1: EMPty, -2: DELeted
};

struct elem* HTp;         // statt struct elem* HT[7000];

int table_is_full(int* HT, int size) {
    for (int i = 0; i < size; i++) {
        if (HT[i] == 0) return 0; // Annahme: 0 = leer
    }
    return 1;
}


int h1(int k) {
    return k % m1;
}

int h2(int k) {
    return m2 - (k % m2);
}

int h3(int k, int i) {
    return (h1(k) + i * h2(k)) % m1;
}


int LinearProbingInsert(int k) {
    if (table_is_full(HTlin, m1)) {
        printf("Hashtable is full\n");
        return -1;
    }
    int probe = h1(k);
    while (HTlin[probe] != 0) {     //Annahme 0 ist leer
        probe = (probe + 1) % m1;
    }
    HTlin[probe] = k;
}

int DoubleHashingInsert(int k) {
    int i = 0;
    int probe = h1(k);
    while (HTdoub[probe] != 0 && i < m1) {
        probe = h3(k,i);
        i++;
    }
    if (i>m1) {printf("Hashtable overflow"); return -1;}
    else HTdoub[probe] = k;
}

void HTinit(struct elem* HT, int size) {
    for (int i = 0; i < size; i++) {
        HT[i].status = -1;
    }
}

int HTinsert(struct elem* HT,int k) {
    int i = -1;
    int probe = h1(k);
    while (i < m1 && HT[probe].status == 0) {
        i++;
        probe = h3(k,i);             //double hashing function
    }
    if (i>=m1) {return -1;}
    HT[probe].status = 0;
    HT[probe].key = k;
    return probe;
}

int HTsearch(struct elem* HT,int k) {
    int i = 0;
    while (i < m1) {
        int probe = h3(k, i);
        if (HT[probe].status == -1) {
            // Slot ist leer, also nicht vorhanden
            return -1;
        }
        if (HT[probe].status == 0 && HT[probe].key == k) {
            // Gefunden
            return probe;
        }
        i++;
    }
    return -1;
}

int HTdelete(struct elem* HT, int k) {
    int i = 0;
    int probe;

    while (i < m1) {
        probe = h3(k, i);
        if (HT[probe].status == -1) {
            // Wenn wir auf einen leeren Slot treffen, ist das Element nicht vorhanden
            return -1;
        }
        if (HT[probe].status == 0 && HT[probe].key == k) {
            // Element gefunden, Status auf -2 (gelöscht) setzen
            HT[probe].status = -2;
            return probe;  // Position des gelöschten Elements zurückgeben
        }
        i++;
    }
    return -1;  // Wenn das Element nicht gefunden wurde
}

void print(int HT[], int size) {
    for (int i = 0; i < size; i++) {
        if (HT[i] == 0) {
            printf("%d: \n", i);  // Wenn der Wert 0 ist, gebe "leer" aus
        } else {
            printf("%d: %d\n", i, HT[i]);  // Andernfalls den tatsächlichen Wert ausgeben
        }
    }
    printf("\n");
}

void printHT(struct elem* HT, int size) {
    for (int i = 0; i < size; i++) {
        if (HT[i].status == -1) {
            printf("%d: empty\n", i);  // Wenn der Status -1 ist, ist der Slot leer
        } else if (HT[i].status == -2) {
            printf("%d: deleted\n", i);  // Wenn der Status -2 ist, wurde das Element gelöscht
        } else {
            printf("%d: key = %d, status = %d\n", i, HT[i].key, HT[i].status);  // Andernfalls wird der Key und Status ausgegeben
        }
    }
    printf("\n");
}

// Funktion, die prüft, ob eine Zahl eine Primzahl ist
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Funktion, die die nächste kleinere Primzahl zurückgibt
int nextSmallerPrime(int n) {
    // Beginne mit der Zahl n-1 und prüfe jede Zahl rückwärts
    for (int i = n - 1; i > 1; i--) {
        if (isPrime(i)) {
            return i;  // Rückgabe der ersten kleineren Primzahl
        }
    }
    return -1;  // Wenn keine kleinere Primzahl gefunden wird (z.B. für 2)
}


int main() {
    // Dynamische Berechnung von m1 und Initialisierung der Arrays
    m1 = sizeA * 2;                                  // Größe des Hash-Tables (doppelt so groß wie die Array-Größe)
    m2 = nextSmallerPrime(m1);                                          // should be neares smaller prime to m1
    HTdoub = (int*)malloc(m1 * sizeof(int));    // Dynamische Zuweisung für Double Hashing
    HTlin = (int*)malloc(m1 * sizeof(int));     // Dynamische Zuweisung für Linear Probing

    // Hashtable für Struct-basierte Methode
    HTp = malloc(m1 * sizeof(struct elem));

    // Initialisierung der Arrays auf 0
    memset(HTlin, 0, m1 * sizeof(int));
    memset(HTdoub, 0, m1 * sizeof(int));

    printf("\nGroesse der Hashtable m1 = sizeofA * 2:  %d\n", m1);
    printf("Naechste kleinere Primzahl zu m1:  %d\n", m2);


    //LinearProbing
    for (int i = 0; i < sizeA; i++) {
        LinearProbingInsert(Array[i]);
    }
    printf("Linear Probing:\n");
    print(HTlin, m1);

    //DoubleHashingInsert
    for (int i = 0; i < sizeA; i++) {
        DoubleHashingInsert(Array[i]);
    }
    printf("DoubleHashingInsert:\n");
    print(HTdoub, m1);

    //Struct HT
    HTinit(HTp, m1);
    for (int i = 0; i < sizeA; i++) {
        HTinsert(HTp, Array[i]);
    }
    printHT(HTp, m1);

    printf("HT Search 109: %d\n", HTsearch(HTp, 109));
    printf("HT Search 115: %d\n", HTsearch(HTp, 115));
    printf("HT Search 102: %d\n", HTsearch(HTp, 102));

    printf("HTdelete\n");
    HTdelete(HTp, 109);
    HTdelete(HTp, 115);
    HTdelete(HTp, 102);
    HTdelete(HTp, 112);
    HTdelete(HTp, 1);

    printHT(HTp, m1);

    printf("HTinsert ArrayB\n");

    int ArrayB[] = {234, 5, 6874, 34, 23 ,66, 0};
    int sizeB = sizeof(ArrayB)/sizeof(ArrayB[0]);
    for (int i = 0; i < sizeB; i++) {
        HTinsert(HTp, ArrayB[i]);
    }
    printHT(HTp, m1);



}