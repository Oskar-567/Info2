//
// Created by Oskar on 21.03.2025.
//

#include <stdio.h>

int Array[] = {-1 ,2, -4, 1, 9, -6, 7, -3, 5};
int size = sizeof(Array)/sizeof(Array[0]);
int lres = 0;
int rres = 0;

void printArray(int A[], int l, int r)
{
  for (int i = l; i <= r; i++) {printf("%d ", A[i]);}
  printf("\n");
}

int Sum(int A[], int l, int r)
{
  int res = 0;
  for (int i = l; i <= r; i++) {res = res + A[i];}
  return res;
}

// Kadane's Algorithmus, um das maximal Summe Subarray zu finden
int kadane(int A[], int n) {
  int max_sum = A[0];
  int current_sum = A[0];
  int start = 0, end = 0, temp_start = 0;

  for (int i = 1; i < n; i++) {
    // Bestimmen, ob wir das Subarray erweitern oder ein neues starten
    if (current_sum + A[i] > A[i]) {current_sum += A[i];}
    else
    {
      current_sum = A[i];
      temp_start = i;  // neuer Startpunkt für das Subarray
    }

    // Wenn current_sum die maximal gefundene Summe übersteigt
    if (current_sum > max_sum) {
      max_sum = current_sum;
      start = temp_start;
      end = i;  // Subarray mit maximaler Summe
    }
  }

  lres = start;
  rres = end;

  return max_sum;
}

int main()
{
  printf("Array : \n");
  printArray(Array, 0, size);
  printf("Sum biggest SubArray: %d\n", kadane(Array, size));
  printf("Max SubArray: \n");
  printArray(Array, lres, rres);
}