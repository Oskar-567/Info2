//
// Created by Oskar on 26.02.2025.
//

#include <stdio.h>
#include <stdbool.h>

int array[10];
int t;


int main ()
{
  printf("Gib den Summand t ein: ");
  scanf("%d", &t);

  printf("Gib 10 Zahlen ein:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("Zahl Nummer %d: ",i + 1);
    scanf("%d", &array[i]);
    //printf("\n");
  }

  printf("Das Array: ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d, ", array[i]);
  }
  printf("\nDer Summand t: %d\n", t);

  for (int i = 0; i < 10; i++)
  {
    for (int j = i+1; j < 10; j++)
    {
      if (array[i] + array[j] == t)
      {
        printf("%d + %d = %d\n",array[i],array[j],t);
        return 1;
      }
    }
  }
  printf("0\n");
  return 0;
}