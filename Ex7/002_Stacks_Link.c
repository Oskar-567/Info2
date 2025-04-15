
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define isEmpty (-1)
#define true 1
#define false 0

//--- STACK ---
//Falsche Runtime da du hinten einfügst. Du musst vorne einfügen um O(1) zu erreichen

struct node
{
  int val;
  struct node* next;
};

struct node* S = NULL;

void new()
{
  struct node* temp;
  while (S != NULL)
  {
    temp = S;
    S = S->next;
    free(temp);
  }
  printf("Stack has been reset\n");
}

int is_empty()
{
  if (S == NULL) {return true;}
  return false;
}

int pop()
{
  if (S == NULL) {return -1;}

  int result = 0;
  struct node* cur;
  cur = S;
  result = cur->val;

  if (cur->next == NULL)
  {
    free(S);
    S = NULL;
  }
  else
  {
    S = cur->next;
    free(cur);
  }
  return result;
}

int push(int x)
{
  struct node *new = malloc(sizeof(struct node));
  struct node* temp = S;
  new->val = x;
  new->next = temp;
  S = new;

}

void print()
{
  struct node *cur = S;
  while(cur != NULL)
  {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}

int main()
{
  printf("Is empty?: %d\n",is_empty());
  new();
  push(1);
  push(20);
  push(5);
  printf("Is empty?: %d\n",is_empty());
  print();
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());
  printf("remove: %d\n", pop());

}