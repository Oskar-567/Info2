
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define isEmpty (-1)
#define true 1
#define false 0

//--- STACK ---

struct node
{
    char val;
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

char pop()
{
  if (S == NULL) {return -1;}

  char result;
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

void check()
{
    if (S == NULL || S->next == NULL){return;}

    struct node* cur;
    struct node* past;

    past = S->next;
    cur = S;

    if ((past->val == '(' && cur->val == ')') || (past->val == '[' && cur->val == ']'))
      {
        pop();
        pop();
      }
}

int push(char x)
{
  struct node *new = malloc(sizeof(struct node));
  struct node* temp = S;
  new->val = x;
  new->next = temp;
  S = new;
  check();

}



void print()
{
    struct node *cur = S;
    while(cur != NULL)
    {
        printf("%c ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    printf("Is empty?: %d\n",is_empty());
    new();

    char A[] = "(())";
    for (int i = 0; i < strlen(A); i++){push(A[i]);}
    printf("Is A empty?: %d\n",is_empty());
    print();

    new();
    char B[] = "[()][]()";
    for (int i = 0; i < strlen(B); i++){push(B[i]);}
    printf("Is B empty?: %d\n",is_empty());
    print();

    new();
    char C[] = "[(])";
    for (int i = 0; i < strlen(C); i++){push(C[i]);}
    printf("Is C empty?: %d\n",is_empty());
    print();

    new();
    char D[] = "[[()]";
    for (int i = 0; i < strlen(D); i++){push(D[i]);}
    printf("Is D empty?: %d\n",is_empty());
    print();

    new();
    char E[] = "(([]))";
    for (int i = 0; i < strlen(E); i++){push(E[i]);}
    printf("Is E empty?: %d\n",is_empty());
    print();

}