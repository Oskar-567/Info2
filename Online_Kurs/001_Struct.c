//
// Created by Oskar on 05.03.2025.
//

#include <stdio.h>

struct Rectangle
{
  int length;
  int breath;
};

void initialize (struct Rectangle *r, int l, int b)
{
  r->length = l;
  r->breath = b;
}

int area (struct Rectangle r)
{
  return r.length*r.breath;
}

void change (struct Rectangle *r, int l)
{
  r->length = l;
}

int main()
{
  struct Rectangle r;
  initialize (&r, 10, 5);
  printf("Area is : %d\n", area (r));
  change (&r, 20);
  printf("Area is : %d\n", area (r));
}