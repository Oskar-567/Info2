
#include <stdio.h>
#include <math.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void Kadanes_algo(int A[], int size) {           //Time complexity O(n)
    int maxSubarray = A[0];                      //finde den grössten Wert in einem zusammenhängendem Subarray
    int currSum = 0;

    for (int i = 0; i < size; i++) {
        if (currSum < 0) {currSum = 0;}
        currSum = currSum + A[i];
        maxSubarray = max(maxSubarray, currSum);
    }
    printf("Kadanes Algorithm (find biggest sum in Subarray)\n");
    printf("Result: %d\n\n", maxSubarray);
}

void MinSizeSubarray(int A[], int size, int targetval) {           //Time complexity O(n)
    int l = 0;                                                     //Findet die kleinste länge des Subarrays, dass zusammen addiert grösser gleich den Target wert ergibt
    int r = 0;
    int sum = 0;
    int windowsize = 99999999;               //oder INFINITY. Gibt aber eine Warnung, weil float als int benutzt wird.
    for (r = 0; r < size; r++) {
        sum = sum +A[r];
        while (sum >= targetval) {
            windowsize = min(r-l + 1, windowsize);
            sum = sum - A[l];
            l++;
        }
    }
    printf("MinSizeSubarray (Smalles Arraylength to sum up to t)\n");
    printf("Result: %d\n\n", windowsize);

}

void Longest_Increasing_Subsequence(int A[], int size) {   //Time complexity O(n^2)
    int B[size];        //alle Werte im Array B = 0
    for (int i = 0; i < size; i++) {
        B[i] = 0;
    }
    int result = 0;
    for (int i = size-1; i >= 0 ; i--) {            //läuft von Links nach rechts durch das Array
        for (int j = i+1; j < size; j++) {          //schaut ob man A[i] mit A[j] kombinieren kann
            if (A[i] < A[j]) {
                B[i] = max(B[i], B[j] + 1);
            }
        }
        result = max(result, B[i]);
    }
    printf("Longest_Increasing_Subsequence\n");
    printf("Result: %d\n\n", result);

}

void Longest_Common_Subsequence(int A[], int B[], int n, int m) {   //Time complexity O(n*m)
    int dp[n+1][m+1];

    // Initialisiere dp-Tabelle mit 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    // Fülle dp-Tabelle nach dem LCS-Prinzip
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Ergebnis: Länge der LCS
    printf("Longest_Common_Subsequence\n");
    printf("Result: %d\n\n", dp[n][m]);
}

void climbingStairs(int n) {        //O(n)
    int one = 1;                    //Fibonacci Numbers
    int two = 1;

    for (int i = 0; i < n-1; i++) {
        int temp = one;
        one = one + two;
        two = temp;
    }
    printf("climbingStairs\n");
    printf("Result: %d\n\n", one);
}

// Rod Cutting (Unbounded Knapsack)             //O(n*rod_length)
void cutRod(int lengths[], int prices[], int numTypes, int rodLength) {
    int dp[rodLength + 1];

    // Anfangswerte setzen
    for (int i = 0; i <= rodLength; i++) {
        dp[i] = 0;
    }

    // Bottom-up DP
    for (int i = 1; i <= rodLength; i++) {
        for (int j = 0; j < numTypes; j++) {
            if (lengths[j] <= i) {
                dp[i] = max(dp[i], prices[j] + dp[i - lengths[j]]); //wenn Stab gleich oder länger als length ist, schneiden wir length ab und haben dann ein max problem, zwischen dem Wert, der schon in der Zelle ist aus vorherigen grössen, oder einen Wert von length, den wir mit dem subproblem dp[i-length] addieren.
            }
        }
    }

    printf("cutRod\n");
    printf("Result: %d\n\n", dp[rodLength]);

}

void coinChange(int coinArray[], int sizecoinList, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++) {
        dp[i]= amount + 1;      //ersetzt hier unendlich
    }

    dp[0] = 0;


    for (int a = 0; a <= amount; a++) {
        for (int c = 0; c < sizecoinList; c++) {
            if (coinArray[c] <= a) {
                dp[a] = min(dp[a], 1 + dp[a - coinArray[c]]);
            }

        }
    }

    printf("coinChange\n");
    printf("Result: %d\n\n", dp[amount]);
}


void knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialisiere DP-Tabelle
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("KnapSack\n");
    printf("Maximaler Gesamtwert im Rucksack: %d\n", dp[n][capacity]);
}





int main() {
    int ArrayA[] = {-2,1,-3,4,-1,2,1,-5,4};
    int sizea = sizeof(ArrayA)/sizeof(ArrayA[0]);
    Kadanes_algo(ArrayA, sizea);

    int ArrayB[] = {2,3,1,2,4,3};
    int sizeb = sizeof(ArrayB)/sizeof(ArrayB[0]);
    MinSizeSubarray(ArrayB, sizeb, 7);

    int ArrayC[] = {1,2,4,3};
    int sizec = sizeof(ArrayC)/sizeof(ArrayC[0]);
    Longest_Increasing_Subsequence(ArrayC, sizec);

    //int ArrayC[] = {1,2,4,3};
    //int sizec = sizeof(Array)/sizeof(Array[0]);
    Longest_Common_Subsequence(ArrayA, ArrayB, sizea, sizeb);

    climbingStairs(5);

    //Cutting Rod
    int lengths[] = {1, 2, 3, 5};          // verfügbare Stablängen
    int prices[]  = {2, 5, 7, 10};         // jeweiliger Preis
    int rodLength = 9;                    // Ziel-Stablänge
    int numTypes = sizeof(lengths) / sizeof(lengths[0]);
    cutRod(lengths, prices, numTypes, rodLength);

    //Coin Change
    int coins[] = {1, 5, 10, 25};
    int sizecoinL = sizeof(coins)/sizeof(coins[0]);
    int amount = 49;

    coinChange(coins, sizecoinL, amount);

    //Knapsack
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 7;

    knapsack(weights, values, n, capacity);

}