//
// Created by Oskar on 31.03.2025.
//

#include <stdio.h>
#include <stdlib.h>

//--- STACK ---

#define MAX 5

struct Stack
{
  int a[MAX];
  int t;
};

struct Stack* create()
{
  struct Stack *s;
  s = malloc(sizeof(struct Stack));
  s->t = -1;
  return s;
}

int StackisEmpty(struct Stack* s)
{
  return (s->t == -1);  // Stack ist leer, wenn top == -1
}

// Überprüfen, ob der Stack voll ist
int StackisFull(struct Stack* s)
{
  return (s->t == MAX - 1);  // Stack ist voll, wenn top == MAX - 1
}

void drop(struct Stack* s)
{
  free(s);
}

void push(struct Stack* s, int x)
{
  s->t++;
  s->a[s->t] = x;
}

int pop(struct Stack* s)
{
  s->t--;
  return s->a[s->t];
}

void displayStack(struct Stack* s) {
  if (StackisEmpty(s)) {
    printf("Der Stack ist leer.\n");
    return;
  }

  printf("Stack-Inhalt: ");
  for (int i = s->t; i >= 0; i--) {
    printf("%d ", s->a[i]);
  }
  printf("\n");
}


//--- QUEUES ---

struct Queue
{
  int a[MAX];
  int h;
  int t;
};

struct Queue* create2()
{
  struct Queue *q;
  q = malloc(sizeof(struct Queue));
  q->t = -1;  //tail
  q->h = -1;  //head
  return q;
}



int isFull(struct Queue* q)
{
  return (q->t == MAX - 1);  // Queue ist voll, wenn tail == MAX - 1
}

int isEmpty(struct Queue* q)
{
  return (q->h == -1);  // Queue ist leer, wenn head == -1
}

void enqueue(struct Queue* q, int value)
{
  if (isFull(q))
  {
    printf("Queue Overflow! Kann %d nicht hinzufuegen.\n", value);
    return;
  }
  if (q->h == -1) {  // Wenn die Queue leer ist, setze head auf 0
    q->h = 0;
  }
  q->a[++q->t] = value;  // Füge das Element am Ende ein
  printf("%d wurde zur Queue hinzugefuegt.\n", value);
}

int dequeue(struct Queue* q) {
  if (isEmpty(q))
  {
    printf("Queue Underflow! Die Queue ist leer.\n");
    return -1;  // Gibt -1 zurück, wenn die Queue leer ist
  }
  int value = q->a[q->h++];
  if (q->h > q->t)     // Wenn die Queue nach dem Entfernen leer ist
  {
    q->h = q->t = -1;  // Setze head und tail auf -1
  }
  printf("%d wurde aus der Queue entfernt.\n", value);
  return value;
}

void displayQueue(struct Queue* q) {
  if (isEmpty(q))
  {
    printf("Die Queue ist leer.\n");
    return;
  }

  printf("Queue-Inhalt: ");
  for (int i = q->h; i <= q->t; i++)
  {
    printf("%d ", q->a[i]);
  }
  printf("\n");
}



int main()
{

  struct Stack* s1 = create();

  push(s1, 10);
  push(s1, 20);
  push(s1, 30);
  displayStack(s1);
  push(s1, 40);
  push(s1, 50);
  displayStack(s1);

  pop(s1);
  pop(s1);
  displayStack(s1);
  pop(s1);
  pop(s1);
  pop(s1);
  displayStack(s1);

  drop(s1);






  struct Queue* q = create2();
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  displayQueue(q);

  // Queue ist jetzt voll, der nächste Enqueue sollte einen Overflow verursachen
  enqueue(q, 60);

  dequeue(q);
  dequeue(q);

  displayQueue(q);

  dequeue(q);
  dequeue(q);
  dequeue(q);

  displayQueue(q);

  free(q);

  return 0;
}