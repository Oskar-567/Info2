//
// Created by Oskar on 26.02.2025.
//

#include <stdio.h>
#include <stdbool.h>

int array[] = {1,2,3,4,5,6,7,8,9};
int size = 9;
int cnum = 17;


int T (int A[], int n, int t)
{
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    if (A[i] + A[n-1] < t) {i++;}
    while (A[i] + A[i+k] <= t)
    {
      if (A[i] + A[i+k] == t)
      {
        return 1;
      }
      k++;
    }
  }
  return 0;
}

int main ()
{
  printf("%d", T (array, size, cnum));
}