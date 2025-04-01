//
// Created by Oskar on 28.03.2025.
//

#include <stdio.h>

int Array1[] = {2,6,4,1,5,3};
int size = sizeof(Array1) / sizeof(Array1[0]);

int Array2[] = {6,8,4,5,3,7,2,1,0,9};
int size2 = sizeof(Array2) / sizeof(Array2[0]);

int Array3[] = {1,9,0,6,3,8,7,2,4,5};
int size3 = sizeof(Array3) / sizeof(Array3[0]);

int Array4[] = {1,3,5,7,8,9,6,4,2,0};                //Array for Task 2.4
int size4 = sizeof(Array4) / sizeof(Array4[0]);

int count = 0;

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
    printf(" changed values \n");
}

int HoarePartition(int A[], int l, int r)
{
    int x = A[r];
    //printf("New HoarePartition l:%d , r:%d , x:%d \n", l, r, x);
    int i = l - 1;
    int j = r + 1;
    while (1)
    {
        do {j = j - 1;} while (A[j] >= x);
        do {i = i + 1;} while (A[i] <= x);
        //printf("i = %d \n", i);
        //printf("j = %d \n", j);
        count++;

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            printArray(A, size);
            printPointer(i, j);

        }

        else {return i;}
    }
}

void quickSort(int A[], int l, int r)
{
  if (l<r)
  {
    int m = HoarePartition(A,l,r);
    quickSort(A,l,m-1);
    quickSort(A,m,r);
  }
}

int main()
{
  printf("--- TASK 2.1 ---\n");
  printf("HoarePartition return value: %d\n \n", HoarePartition(Array1, 0, size-1));    //Task 2.1
  printf("--- TASK 2.2 ---\n");
  quickSort(Array1, 0, size-1);                         //Task 2.2
  printf("\n \n");

  printf("--- TASK 2.3 ---\n");
  count = 0;                            //Task 2.3
  size = size2;
  quickSort(Array2, 0, size2-1);
  printf("counter innermost Loop: %d \n\n", count);
  count = 0;
  quickSort(Array3, 0, size3-1);
  printf("counter innermost Loop: %d \n\n", count);

  printf("--- TASK 2.4 ---\n");
  count = 0;                            //Task 2.4
  size = size4;
  quickSort(Array4, 0, size4-1);
  printf("counter innermost Loop: %d \n\n", count);


}
