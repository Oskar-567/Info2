//
// Created by Oskar on 10.03.2025.
//

#include <stdio.h>
#include <stdlib.h>

int arrayA[]={5,2,4,7,1,3,6,2};
int arrayB[]={5,2,4,7,1,3,6,2};

int n = sizeof(arrayA)/sizeof(arrayA[0]);

void Printarray(int A[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}


void Merge(int arr[], int left, int right, int mid) {
  int i,j,k;

  for (i = 0; i <= mid; i++) {arrayB[i] = arr[i];}
  for (i = mid+1; i <= right; i++) {arrayB[right + mid - i+1] = arr[i];}
  i = left; j=right;
  for (k = left; k <= right; k++)
  {
    if (arrayB[i] <= arrayB[j]) {arr[k] = arrayB[i]; i++; }
    else {arr[k] = arrayB[j]; j-- ;}
  }
  }

void MergeSort(int A[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    //printf("Mid %d \n", mid);
    MergeSort(A,left,mid);
    MergeSort(A,mid+1,right);
    //Printarray(A,right);
    Merge(A,left,right,mid);
  }
}



int main()
{
  printf("Array unsorted:\n");
  Printarray(arrayA, n-1);

  MergeSort(arrayA, 0, n-1);

  printf("Array sorted:\n");
  Printarray(arrayA, n-1);

}