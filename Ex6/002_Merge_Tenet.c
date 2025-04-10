
#include <stdio.h>
#include <stdlib.h>

int A[] = {2,4,7,9};
int sizea = (sizeof(A) / sizeof(A[0]));
int B[] = {1,6,12};
int sizeb = (sizeof(B) / sizeof(B[0]));



struct node
{
  int val;
  struct node *next;
  struct node *prev;
};

void print(struct node *p)
{
  struct node *pointer = p;
  printf("Array \n");
  while (pointer != NULL)
    {
      printf("%d ", pointer->val);
      pointer = pointer->next;
    }
  printf("\n");
}


struct node* create(int Array[], int size)
{
  if (size == 0) {return NULL;}

  struct node* p;
  struct node* head;
  head = malloc(sizeof(struct node));
  head->val = Array[0];
  head->prev = NULL;

  p = head;
  for (int i = 1; i < size; i++)
  {
    struct node* temp = malloc(sizeof(struct node));
    temp->val = Array[i];
    temp->prev = p;
    p->next = temp;
    p = temp;
  }
  p->next = NULL;

  return head;
}

struct node* merge(struct node* a, struct node* b)
{
  if (a == NULL) {return b;}
  if (b == NULL) {return a;}
  struct node* p1 = a;
  struct node* p2 = b;
  struct node* new;
  struct node* temp;

  if (p1->val <= p2->val)  //erstes Element
  {
    new = p1;
    p1 = p1->next;
  }
  else {new = p2; p2 = p2->next;}
  temp = new;

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->val <= p2->val)
    {
      temp->next = p1;
      p1->prev = temp;
      p1 = p1->next;
    }
    else
    {
      temp->next = p2;
      p2->prev = temp;
      p2 = p2->next;
    }
    temp = temp->next;
  }

  if (p2 == NULL)
  {
    temp->next = p1;
    p1->prev = temp;
    return new;
  }
  if (p1 == NULL)
  {
    temp->next = p2;
    p2->prev = temp;
    return new;
  }

  return new;
}

struct node* reverse(struct node* a)
{
  struct node* current = a;
  struct node* temp = NULL;

  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }


  if (temp != NULL)
  {
    a = temp->prev;
  }
  return a;
}

int main()
{
  struct node *Array1 = create(A,sizea);
  struct node *Array2 = create(B,sizeb);

  print(Array1);
  print(Array2);

  struct node *MergeArray = merge(Array1, Array2);
  printf("Merge Array\n");
  print(MergeArray);

  printf("\nReverse List");
  struct node *ReverseArray = reverse(MergeArray);
  print(ReverseArray);

}