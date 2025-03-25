//
// Created by Oskar on 21.03.2025.
//


#include <stdio.h>
#include <math.h>

int Array[] = {0 ,2, 3, 4, 5, 6, 7, 11, 14, 15};
int size = sizeof(Array)/sizeof(Array[0]);
int t = 8;

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++) {printf("%d ", A[i]);}
  printf("\n");
}

int closestNumber(int A[],int key)
{
  int l = 0;
  int r = size - 1;
  int m = (l+r)/2;
  while (l<=r && key != A[m])
  {
    if (key < A[m]) {r = m-1;}
    if (key > A[m]) {l = m+1;}
    m = (l+r)/2;
  }
  if (l<=r) {return A[m];}
  if (sqrt( pow(A[r]-t, 2)) > sqrt( pow(A[l]-t, 2))) {return A[l];}
  else {return A[r];}
  }

int main()
{
  printf("Array : \n");
  printArray(Array, size);
  printf("Closest Number: %d \n", closestNumber(Array, t));
}