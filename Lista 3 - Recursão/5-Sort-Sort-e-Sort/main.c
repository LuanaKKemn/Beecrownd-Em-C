#include <stdio.h>
#include <stdlib.h>

int ord(int n1, int n2, int y){
  int parn1 = (n1 % 2 == 0) ? 1 : 0,
      parn2 = (n2 % 2 == 0) ? 1 : 0;

  // Caso haja empate
  if(n1 % y == n2 % y){

    if((!parn1) && (parn2)) 
      return 1;
    if((parn1) && (!parn2)) 
      return -1;
    if((!parn1) && (!parn2)) 
      return (n1 <= n2) ? 1 : -1;
    if((parn1) && (parn2)) return -1;
      return (n1 >= n2) ? 1 : -1;
  }

  int n = (n2 - n1);
  return n == 0 ? 0 : (n > 0) ? 1 : -1;
}

int *selection_sort(int *vet, int n, int m){
  int menor;
  for(int i=0; i<n; i++){
    menor = i;
    for(int j=i+1; j<n; j++){
      if(ord(vet[j], vet[menor], m) == 1)
        menor = j;
    }
    if(menor != i){
      int temp = vet[menor];
      vet[menor] = vet[i];
      vet[i] = temp;
    }
  }
}

int main(void) {

  // Entrada de dados
  int n, m;
  scanf("%d %d", &n, &m);
  int *vet = (int *) malloc(sizeof(int) * n);
  for(int i=0; i<n; i++)
    scanf("%d", &vet[i]);

  // Chama a função de ordenação
  selection_sort(vet, n, m);

  
  // Printa o vetor
  printf("\n");
  for(int i=0; i<n; i++)
    printf("%d ", vet[i]);
  
  
  return 0;
}

// 15 3
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15

// 15
// 9
// 3
// 6
// 12
// 13
// 7
// 1
// 4
// 10
// 11
// 5
// 2
// 8
// 14