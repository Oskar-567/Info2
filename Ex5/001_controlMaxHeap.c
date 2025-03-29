//
// Created by Oskar on 28.03.2025.
//

#include <stdio.h>

int Array1[] = {5, 5, 3, 2, 1, 3};
int Array2[] = {5, 5, 3, 2, 1, 4};
int Array3[] = {5, 5, 3, 2, 1, 6};
int size = sizeof(Array1)/sizeof(Array1[0]);

int Array4[] = {4, 10, 3, 5, 1 };
int index4 = 0;
int size4 = sizeof(Array4)/sizeof(Array4[0]);

int Array5[] = {5, 5, 3, 2, 1, 4, 2};
int size5 = sizeof(Array5)/sizeof(Array5[0]);


void printArray(int A[], int s)
{
  for (int i=0 ; i<s; i++) {printf("%d ", A[i]);}
  printf("\n");
}

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

void heapify(int A[], int i, int s)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    if (l < s && A[l] > A[m]) {m = l;}
    if (r < s && A[r] > A[m]) {m = r;}
    if (i != m)
    {
      int copy = A[i];
      A[i] = A[m];
      A[m] = copy;
      i =m;
      heapify(A, m, s);
    }
}

void fixHeap(int A[], int s)
{
  int m = (size/2)-1;
  int w = controlMaxHeap(A, m, s);
  if (w > -1) {heapify(A, w, s);}
}



int main()
{
  int m = (size/2)-1;
  printf("Control Max Heap Array 1: %d \n",controlMaxHeap(Array1, m, size));  //Task 1.1
  printf("Control Max Heap Array 2: %d \n",controlMaxHeap(Array2, m, size));
  printf("Control Max Heap Array 3: %d \n",controlMaxHeap(Array3, m, size));

  printf("Heapify Array \n");    // Task 1.2
  printArray(Array4, size4);
  printf("with index %d\n", index4);
  heapify(Array4, index4, size4);
  printArray(Array4, size4);

  printf("Wrong MaxHeap \n");    // Task 1.3
  printArray(Array5, size5);
  fixHeap(Array5, size5);
  printf("correct MaxHeap \n");
  printArray(Array5, size5);

}