#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX 10100

int n, m;
int compara(int *, int *);

int main (){

  int i;
  int vetor[MAX];

  while (scanf("%d %d", &n, &m), n)
  {

    for (i = 0; i < n; ++i)
      scanf("%d", &vetor[i]);

    qsort(vetor, n, sizeof(int), compara);

    printf("\n%d %d", n, m);
    for (i = 0; i < n; ++i)
      printf("\n%d", vetor[i]);


  }

  printf("%d %d\n", n, m);
  return 0;
}


int compara(int *a, int *b){

  if (*a % m == *b % m)
  {

    if ((*a & 1) && !(*b & 1))
      return -1;
    else if (!(*a & 1) && (*b & 1))
      return 1;
    else if ((*a & 1) && (*b & 1))
    {

      if (*a > *b)
        return -1;
      else
        return 1;

    }
    else if (!(*a & 1) && !(*b & 1))
    {

      if (*a > *b)
        return 1;
      else
        return -1;

    }

  }
  else if (*a % m > *b % m)
    return 1;
  else
    return -1;

}