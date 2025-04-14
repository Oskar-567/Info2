

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define isEmpty (-1)
#define true 1
#define false 0
#define queuesize 100

//--- STACK ---

// Task 1.1
int S[MAX];
int StackArrayIndex = 0;

void newArrayStack()
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





struct stack
{
  int a[MAX];
  int position;
};

struct stack *new()
{
  struct stack *p = malloc(sizeof(struct stack));
  p->position = 0;
}

struct stack *is_empty(struct stack *p)
{
  if (p->position ==0){return true;}
}



int main()
{
  struct stack* S = new();
  is_empty(S);
}
