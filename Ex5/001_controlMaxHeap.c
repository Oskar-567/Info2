//
// Created by Oskar on 28.03.2025.
//

#include <stdio.h>

int Array1[] = {5, 5, 3, 2, 1, 3};
int Array2[] = {5, 5, 3, 2, 1, 4};
int Array3[] = {5, 5, 3, 2, 1, 6};
int size = sizeof(Array1)/sizeof(Array1[0]);

int controlMaxHeap(int A[], int i, int s)
{
  for (; i >= 0; i--)
  {
    int l = 2 * i  + 1;
    int r = 2 * i  + 2;
    if ((l < s && A[l] > A[i]) || (r < s && A[r] > A[i])) {return i;}
  }
  return -1;
}



int main()
{
  int m = (size/2)-1;
  printf("Control Max Heap Array 1: %d \n",controlMaxHeap(Array1, m, size));
  printf("Control Max Heap Array 2: %d \n",controlMaxHeap(Array2, m, size));
  printf("Control Max Heap Array 3: %d \n",controlMaxHeap(Array3, m, size));
}