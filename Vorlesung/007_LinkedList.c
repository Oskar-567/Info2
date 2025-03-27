//
// Created by Oskar on 27.03.2025.
//

#include <stdio.h>
#include <stdlib.h>

int Array[]={5, 2, 4, 7, 1, 3, 6, 2};
int Array2[]={12, 13, 14, 18, 19, 25, 57, 90};
int s = 6;     //count the occurrences of integer s in linked list
int u = 123;   //insert 123 at the beginning
int e = 43;    //insert 43 at the end
int d = 7;     //delete 7

struct node
{
  int val;
  struct node *next;
};

struct node* root;
struct node* root2;

void create(int A[], int n)
{
  struct node *t,*last;
  root=malloc(sizeof(struct node));
  root->val=A[0];
  root->next=NULL;
  last=root;

  for(int i=1;i<n;i++)
  {
    t=malloc(sizeof(struct node));
    t->val=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }

}

void count(struct node *p, int i)
{
  int x = 0;
  while(p!=NULL)
  {
    if (p->val == s) {x++;}
    p=p->next;
  }
  printf("Number: %d is %d times in list \n",s,x);
}

void display(struct node *p)
{
  while(p!=NULL)
  {
    printf("%d ",p->val);
    p=p->next;
  }
  printf("\n");
}

void insertbeginning(struct node *p, int i)
{
  struct node *t;
  t=malloc(sizeof(struct node));
  t->val=i;
  t->next=root;
  root=t;

  printf("Insert %d at the beginning; New Array:\n",i);
  display(root);
}

void linkLists(struct node *p, struct node *q)
{
  printf("Linked the two Arrays:\n");
  display(p);
  display(q);

  while (p != NULL && p->next != NULL) {p = p->next;}
  p->next = q;


  printf("New:\n");
  display(root);
}

void insertend(struct node *p, int i)
{
  if (root == NULL)
  {
    root = malloc(sizeof(struct node));
    root->val=i;
    root->next=NULL;
  }
  else
  {
    while (p->next != NULL) {p = p->next;}
    p->next = malloc(sizeof(struct node));
    p->val=i;
    p->next=NULL;
  }

  printf("Insert %d at the end:\n", i);
  display(root);
}

void delete(struct node *p, int i)
{
  struct node *temp;
  temp = p;
  if (p->val == i)
  {
    root = temp->next;
    free (temp);
  }
  else
  {
    while (p->next != NULL && p->next->val != i) {p=p->next;}
  }
  temp = p->next;
  p->next = temp->next;
  free(temp);

  printf("Delete %d; New Array:\n",i);
  display(root);

}


int main()
{
  create(Array, 8);
  display(root);
  count(root, s);
  insertbeginning(root, u);
  insertend(root, e);
  delete(root, d);

  root2 = root;
  create(Array2, 8);
  linkLists(root, root2);
  free(root);
  return 0;
}

