//
// Created by Oskar on 19.03.2025.
//

#include <stdio.h>

int Array[] = {6, 0, 5, 9, 4, 1, 3, 7, 8, 2};
int size = sizeof(Array)/sizeof(Array[0]);

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}


int Heapify(int A[], int i, int s)
{
  int m = i;
  int l = 2 * i  + 1;
  int r = 2 * i  + 2;
  if (l < s && A[l] > A[m]) {m = l;}
  if (r < s && A[r] > A[m]) {m = r;}
  if (i != m)
  {
    int t;
    t = A[i];
    A[i] = A[m];
    A[m] = t;
    Heapify(A, m, s);
  }
}

int BuildHeap(int A[], int n)
{
  int i;
  for (i = (n/2) - 1 ; i >= 0; i--) {Heapify(A, i, n);}
  printf("Heapify Array :\n");
  printArray(A, n);
}

int HeapSort(int A[],int n)
{
  int s = n;
  BuildHeap(A,n);
  for (int i=n - 1; i>=1; i--)
  {
    int t = A[0];
    A[0] = A[i];
    A[i] = t;
    s = s-1;
    Heapify(A, 0, s);
  }
}

int main()
{
  printf("Unsorted Array : \n");
  printArray(Array, size);
  HeapSort(Array, size);
  printf("Sorted Array : \n");
  printArray(Array, size);

}