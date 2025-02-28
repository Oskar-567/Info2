//
// Created by Oskar on 21.02.2025.
//

#include <stdio.h>
int size = 9;
int A[] = {9, 2, 5, 6, 7, 1, 3, 8, 4};

int main ()
{
  for (int i = 1; i < size ; i++)
  {



    for (int j = 0; j < size-1; j++)
    {

      if (A[j] > A[j + 1])
      {
        int t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;

      }

    }
    printf("i:%d ---", i);
    for (int z = 0; z < 9; z++)
    {
      printf(" %d", A[z]);


    }
    printf("\n");
  }

  for (int i = 0; i < size; i++)
  {
    printf(" %d", A[i]);

  }

}