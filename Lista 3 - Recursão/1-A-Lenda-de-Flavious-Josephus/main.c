#include <stdio.h>
#include <stdlib.h>

/*
  Entrada
  Haverá NC (1 ≤ NC ≤ 30 ) casos de teste. Em cada caso de teste de entrada haverá um par de números inteiros positivos n (1 ≤ n ≤ 10000 ) e k (1 ≤ k ≤ 1000). O  número n representa a quantidade de pessoas no círculo, numeradas de 1 até n. O número k representa o tamanho do salto de um homem até o próximo homem que será morto.
*/

void mallocarVetor(int **vetor, int nc);

int lenda_FS(int n, int k);

int main(void) {
  int nc;
  int n, k;
  int pessoa = 1;

  scanf("%d", &nc);
  int *casos;
  mallocarVetor(&casos, nc);

  
  for (int i=0; i<nc; i++){
    scanf("%d %d", &n, &k);
    int valor = lenda_FS(n, k);
    casos[i] = valor; // COLOCA CADA CASO NO VETOR // 
  }


  // SAIDA //
  for (int i=0; i<nc; i++){
    printf("Case %d: %d", i+1, casos[i]);
  }

  free(casos);
  return 0;
}


void mallocarVetor(int **vetor, int nc){
  *vetor = (int*) malloc (sizeof(int) * nc);
  if (*vetor == NULL){
    printf("Espaço Insuficiente.\n");
    exit(1);
  }
}


int lenda_FS(int n, int k, int *pessoa){
  // vai de 1 ate n -->       pulando k --> entao soma k

  // NÃO ENTENDI COMO USAR RESCURSIVA NISSO
  
  if ((*pessoa + k) > n) {
    (*pessoa) += ((*pessoa + k) - n);
  }
  
  
  return lenda_FS(n+k, k);
}
  
