//
// Created by Oskar on 28.02.2025.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int Array[] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(Array)/sizeof(int);
int v = 7;

int BinarySearch(int A[], int key)
{
    int l = 0;
    int r = n-1;
    int m = floor((l+r)/2);

    while((l<=r) && key!=A[m])
    {
        if(key<A[m]) {r = m-1;}
        else {l = m+1;}
        m = floor((l+r)/2);
    }
    if (l<=r) {return m;}
    else {return -1;}
}


int main()
{
  printf("The Index of the searched number in the array is: %d", BinarySearch(Array, v));
}
