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

int HoarePartition(int A[], int l, int r)
{
  int x = A[r];
  int i = l;
  int j = r;
  while (i < j)
  {
    while (A[j] > x){j = j - 1;}
    while (A[i] < x){i = i + 1;}
    if (i < j)
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
    else return i;
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