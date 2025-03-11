//
// Created by Oskar on 10.03.2025.
//

# include <stdio.h>

void sequence(int n)
{
  printf("%d ",n);
  if(n == 1)
  {
    return;
  }

  if(n%2 == 0)
  {

    n = n/2;
  }
  else
  {
    n = 3*n+1;
  }
  sequence(n);

}

int main()
{
  sequence(3);
}