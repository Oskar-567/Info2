
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

struct node* head;
struct node* tail;

void new()
{
    head = tail = NULL;
    printf("Stack has been reset\n");
}

bool is_empty()
{
    return (head == NULL && tail == NULL);
}

int dequeue()
{
    int result;
    if (is_empty())
    {
        return -1;
    }

    struct node* temp = head;
    result = temp->val;
    if (head == tail)
    {
      free(head);
      head = tail = NULL;
      return result;
    }
    else
    {
      head = head->next;
      free(temp);
      return result;
    }
}

int enqueue(int x)
{
    struct node *new = malloc(sizeof(struct node));
    new->val = x;
    new->next = NULL;

    if (is_empty()) {head = tail = new;}
    else
    {
      tail->next = new;
      tail = new;
    }
}

void print()
{
    struct node *cur = head;
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