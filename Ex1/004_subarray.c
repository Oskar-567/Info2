//
// Created by Oskar on 26.02.2025.
//

#include <stdio.h>
#include <stdbool.h>

int array[] = {9, -2,-1, 1,2,3,4,5,6};
int size = 9;


int zeroSubarray (int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int k = A[i];
    for (int j = i+1; j < size; j++)
    {
      k = k + A[j];
      if (k == 0)
      {
        return 1;
      }
    }
  }
  return 0;
}

int main ()
{
  printf("%d", zeroSubarray(array, size));
}