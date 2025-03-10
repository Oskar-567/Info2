//
// Created by Oskar on 10.03.2025.
//

#include <stdio.h>
#include <stdlib.h>

int array[]={5,2,4,7,1,3,6,2};

void Printarray(int A[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}


void Merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
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
    Merge(A,left,mid,right);
  }
}




int main()
{
  int l = 0;
  int r = sizeof(array)/sizeof(array[0]);
  printf("Array unsorted:\n");
  Printarray(array, r);

  MergeSort(array, l, r);

  printf("Array sorted:\n");
  Printarray(array, r);

}