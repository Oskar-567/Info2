//
// Created by Oskar on 19.02.2025.
//

#include <stdio.h>

int size = 5;
int a[] = {1290, 1290, 4, -3, 22};
int b[5];


int largestnumber(int arr[], int s)
{
  int num = arr[0];
  for(int i = 0; i < size; i++)
  {
    if(arr[i] > num)
    {
      num = arr[i];
    }

  }

  return num;
}

int main()
{
  int lnum = largestnumber(a, size);
  for(int i = 0; i < size; i++)
  {
    if(a[i] != lnum)
    {
      b[i] = a[i];
    }

  }
  int l2num = largestnumber(b, size);
  printf("Largest number: %d\n", lnum);
  printf("2nd largest number: %d\n", l2num);

  int z = sizeof(a) / sizeof(a[0]);
  printf("Size of z: %d\n", z);
  printf("Size of a: %d\n", sizeof(a));
  //for ( int x:a){
  //  printf("%d\n", x);
  //}


  return l2num;

}