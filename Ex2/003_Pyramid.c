//
// Created by Oskar on 10.03.2025.
//

# include <stdio.h>

void printarray(int A[],int size)
{
  for(int i=0;i<=size;i++)
    printf("%d ",A[i]);
  printf("\n");
}

void pyramid(int A[], int size)
{
  if(size==0)
  {
    return;
  }
  int B[size - 1];
  for(int i=0;i<size;i++)
  {
    B[i]=A[i]+A[i+1];
  }
  pyramid(B, size - 1);
  printarray(B,size-1);
}

int main()
{
  int A[] = {5,4,6,1,3};
  int s = 4;
  pyramid(A,s);
  printarray(A,s);
}