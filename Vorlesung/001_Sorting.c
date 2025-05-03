//
// Created by Oskar on 21.02.2025.
//

#include <stdio.h>

//int A[] = {9, 2, 5, 6, 7, 1, 3, 8, 4};
int Array1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int Array2[] = {5, 7, 3, 8, 6, 4, 2, 1, 9};
int Array3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int Array4[] = {5, 7, 3, 8, 6, 4, 2, 1, 9};
int s = sizeof(Array1)/sizeof(Array1[0]);




void printline(int A[], int size, int i)
{
    printf("i:%d ---", i);
    for (int z = 0; z < 9; z++) {printf(" %d", A[z]);}
    printf("\n");
}

void BubbleSort(int A[], int size)
{
    printf("Bubble sort \n");
    for (int i = 1; i < size ; i++)         //for each size-1 element
    {
        for (int j = 0; j < size-i; j++)    //in each line do size-i checks
        {
            if (A[j] > A[j + 1])
            {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
        }
        printline(A, size, i);
    }
    printf("\n");
}

void BubbleSortreverse(int A[], int size)
{
    printf("Bubble sort (mit groessten Elementen links) \n");
    for (int i = 1; i < size; i++)                  // für jedes Element, bis size-1
    {
        for (int j = size - 1; j >= i; j--)         // für jedes Element, aber rückwärts
        {
            if (A[j] > A[j - 1])                    // Wenn das aktuelle Element größer ist als das vorherige
            {
                int t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
        }
        printline(A, size, i);
    }
    printf("\n");
}

void SelectionSort(int A[], int size)
{
  printf("Selection sort \n");
  for (int i = 0; i < size-1; i++)
  {
    int k = i;
    for (int j = i+1; j < size; j++)
    {
      if (A[k] > A[j]) {k=j;}
    }
    int t = A[i];
    A[i] = A[k];
    A[k] = t;

    printline(A, size, i);
  }
  printf("\n");
}

void InsertionSort(int A[], int size)
{
  printf("Insertion sort \n");
  for (int i = 1; i < size; i++)
  {
    int j = i-1;
    int t = A[i];
    while (j >= 0 && A[j] > t)
    {
      A[j+1] = A[j];
      j = j-1;
    }
    A[j+1] = t;

    printline(A, size, i);
  }
  printf("\n");

}



int main ()
{
  BubbleSort(Array1, s);
  SelectionSort(Array2, s);
  InsertionSort(Array3, s);
  BubbleSortreverse(Array4, s);
}