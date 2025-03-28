//
// Created by Oskar on 21.02.2025.
//

#include <stdio.h>

//int A[] = {9, 2, 5, 6, 7, 1, 3, 8, 4};
int Array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int s = sizeof(Array)/sizeof(Array[0]);


void printline(int A[], int size, int i)
{
    printf("i:%d ---", i);
    for (int z = 0; z < 9; z++) {printf(" %d", A[z]);}
    printf("\n");
}

void BubbleSort(int A[], int size)
{
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
}

int main ()
{
  BubbleSort(Array, s);
}