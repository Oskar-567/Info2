//
// Created by Oskar on 21.03.2025.
//

#include <stdio.h>

int Array[] = {6, 5, 2, 7, 9, 3, 0, 4};
int size = sizeof(Array)/sizeof(Array[0]);
int m;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++) {printf("%d ", A[i]);}
    printf("\n");
}

void printPointer(int i, int j)
{
  for (int k=0; k < size; k++)
  {
    if (k == i || k == j){printf("^ ");}
    else {printf("  ");}
  }
  printf(" changed values \n\n");
}

int HoarePartition(int A[], int l, int r)
{
  int x = A[r];
  printf("New HoarePartition l:%d , r:%d , x:%d \n", l, r, x);
  int i = l - 1;
  int j = r + 1;
  while (1)
  {
    do {j = j - 1;} while (A[j] >= x);
    do {i = i + 1;} while (A[i] <= x);
    printf("i = %d \n", i);
    printf("j = %d \n", j);

    if (i < j)
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      printArray(A, size);
      //printf("   changed values: %d & %d\n", A[i], A[j]);
      printPointer(i, j);
    }
    else {return i;}
  }
}

void QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        m = HoarePartition(A,l,r);
        QuickSort(A,l,m-1);
        QuickSort(A,m,r);
    }
}

int main()
{
    printf("Unsorted Array : \n");
    printArray(Array, size);
    QuickSort(Array, 0, size-1);
    printf("Sorted Array : \n");
    printArray(Array, size);

}