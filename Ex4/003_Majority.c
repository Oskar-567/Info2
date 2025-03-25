//
// Created by Oskar on 21.03.2025.
//

#include <stdio.h>

int Array[] = {-1 ,2, -4, 1, 2, -6, 2, -3, 2, 2};
int size = sizeof(Array)/sizeof(Array[0]);

void printArray(int A[], int l, int r)
{
    for (int i = l; i < r; i++) {printf("%d ", A[i]);}
    printf("\n");
}

int majority(int A[], int l, int r)
{
    if (l == r) {return A[l];}
    int mid = (l + r) / 2;
    printf("mid: %d   ", mid);
    printf("l: %d   ", l);
    printf("r: %d \n", r);
    int leftmajority = majority(A, l, mid);
    int rightmajority = majority(A, mid + 1, r);
    if (leftmajority == rightmajority) {return leftmajority;}

    int countLeft = 0;
    int countRight = 0;
    for (int i = l; i <= r; i++)
    {
      if (A[i] == leftmajority) {countLeft++;}
      else if (A[i] == rightmajority) {countRight++;}
    }

    printf("leftmajority: %d \n", leftmajority);
    printf("rightmajority: %d \n", rightmajority);
    printf("countLeft: %d \n", countLeft);
    printf("countRight: %d \n", countRight);

    if (countLeft >= countRight) {return leftmajority;}
    return rightmajority;
}


int main()
{
    printf("Array : \n");
    printArray(Array, 0, size);
    printf("biggest Element in Array: %d\n", majority(Array, 0, size-1));
}