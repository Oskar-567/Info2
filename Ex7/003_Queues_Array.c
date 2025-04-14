
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10
#define isEmpty (-1)
#define true 1
#define false 0

//--- QUEUES ---

int Q[MAX];
int head = 0;
int tail = 0;

void new()
{
  head = 0;
  tail = 0;
  printf("Queues has been reset\n");
}

int is_empty()
{
  if(head == tail){return true;}
  else return false;
}

int dequeue()
{
  if(head==tail) {return -1;}
  int pos = head;
  head = (head + 1) % MAX;
  return Q[pos];
}

int enqueue(int x)
{
  if ((tail + 1) % MAX == head) {printf("Queue is full\n");}
  else
  {
    Q[tail] = x;
    tail = (tail + 1) % MAX;
  }
}

void print()
{
  if (is_empty()) {
    printf("Queue is empty\n");
    return;
  }

  int i = head;
  while (i != tail) {
    printf("%d ", Q[i]);
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main()
{
  printf("Is empty?: %d\n",is_empty());
  int A[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0; i < 10; i++){enqueue(A[i]);}
  print();
  for (int i = 0; i < 5; i++){printf("dequeue %d\n",dequeue());}
  for (int i = 0; i < 3; i++){enqueue(A[i]);}
  print();
  for (int i = 0; i < 8; i++){printf("dequeue %d\n",dequeue());}

  
}