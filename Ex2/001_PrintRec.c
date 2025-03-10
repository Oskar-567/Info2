//
// Created by Oskar on 10.03.2025.
//

#include <stdio.h>
int z =20;

void printRec(int n)
{
  if(n==0){return;}

  printRec(n/2);
  printf("%d",n%2);
}

int main()
{
  printRec(z);
}