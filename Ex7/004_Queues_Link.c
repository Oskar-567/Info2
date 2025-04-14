
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define isEmpty (-1)
#define true 1
#define false 0

//--- QUEUES ---

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

int dequeue()
{
    int result;
    if (S == NULL)
    {
        return -1;
    }

    struct node* temp = S;
    result = temp->val;
    S = S->next;
    free(temp);

    return result;
}

int enqueue(int x)
{
    struct node *new = malloc(sizeof(struct node));
    new->val = x;
    new->next = NULL;
    struct node *cur = S;

    if (S == NULL) {S = new;}
    else
    {
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new;
    }
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
  int A[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0; i < 10; i++){enqueue(A[i]);}
  print();
  printf("Is empty?: %d\n",is_empty());
  for (int i = 0; i < 5; i++){printf("dequeue %d\n",dequeue());}
  for (int i = 0; i < 3; i++){enqueue(A[i]);}
  print();
  for (int i = 0; i < 8; i++){printf("dequeue %d\n",dequeue());}


}