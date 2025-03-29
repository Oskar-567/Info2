//
// Created by Oskar on 28.03.2025.
//

#include <stdio.h>

int Array1[] = {5,2,8,3,7};
int size1 = sizeof(Array1) / sizeof(Array1[0]);

int Array2[] = {5,2,8,3,7,4};
int size2 = sizeof(Array2) / sizeof(Array2[0]);

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++) {printf("%d ", A[i]);}
  printf("\n");
}

void heapify(int A[], int i, int s)
{
  int m = i;
  int l = 2 * i  + 1;
  int r = 2 * i  + 2;
  if (l < s && A[l] > A[m]) {m = l;}
  if (r < s && A[r] > A[m]) {m = r;}
  if (i != m)
  {
    int t = A[i];
    A[i] = A[m];
    A[m] = t;
    heapify(A, m, s);
  }
}

void buildheap(int A[], int n)
{
  for (int i = (n/2) - 1 ; i >= 0; i--) {heapify(A, i, n);}
}

void heapsort(int A[], int n, int half)
{
  int z = n;
  for (int i = n-1; i >= half; i--)
  {
    int temp = A[0];
    A[0] = A[i];
    A[i] = temp;
    z = z-1;
    //printArray(A, n);
    heapify(A, 0 ,z);
  }
}

void findMedian(int A[], int s)
{
  buildheap(A, s);
  if (s%2 == 0)
  {
    int k = (s/2)-1;
    heapsort(A, s, k);
    //printArray(A,s);
    float res = (A[k]+A[k+1]) /2.0;
    printf("Median of Array: %.1f\n", res);
  }
  else
  {
    int k = s/2;
    heapsort(A, s, k);
    //printArray(A,s);
    printf("Median of Array: %d\n", A[k]);
  }

}

int main()
{
  findMedian(Array1, size1);
  findMedian(Array2, size2);

}