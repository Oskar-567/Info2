

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define isEmpty (-1)
#define true 1
#define false 0

//--- STACK ---

// Task 1.1
int S[MAX];
int StackArrayIndex = 0;

void new()
{
  StackArrayIndex = 0;
  printf("Array has been reset\n");
}

int is_empty()
{
  if (StackArrayIndex == 0) {return true;}
  return false;
}

int pop()
{
  if (is_empty() == false) {return S[--StackArrayIndex];}
  return isEmpty;
}

int push(int x)
{
  S[StackArrayIndex++] = x;
}

void print()
{
  for (int i = 0; i < StackArrayIndex; i++)
  {
    printf("%d ",S[i]);
  }
  printf("\n");
}


int main()
{
  new();
  printf("%d\n",is_empty());
  push(5);
  push(8);
  push(15);
  print();
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());

}
