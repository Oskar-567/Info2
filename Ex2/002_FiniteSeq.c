//
// Created by Oskar on 10.03.2025.
//

# include <stdio.h>

void sequence(int n)
{
  if(n == 0)
  {
    return;
  }

  if(n%2 == 0)
  {
    printf("%d ",n/2);
  }
  else
  {
    printf("%d ",3 * n + 1);
  }
  sequence(n-1);

}

int main()
{
  sequence(3);
}