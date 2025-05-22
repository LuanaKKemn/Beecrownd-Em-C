#include <stdio.h>
#include <stdlib.h>

int conta_repetidos(int n, int m, int *vetorNum, int *count);

void mallocarVetorNum(int n, int **vetorNum);


int main(void) {
  int *vetorNum;
  int n, m;
  int count = 0;

  printf("Digite n m:\n");
  scanf("%d %d", &n, &m);
  
  mallocarVetorNum(n, &vetorNum);


  printf("%d", conta_repetidos(n, m, vetorNum, &count));

  free(vetorNum);
  return 0;
}


// RECURSIVONA // 
int conta_repetidos(int n, int m, int *vetorNum, int *count){
  if (n > m){ // --> caso base
    return *count;
  }

  
  // transformar em função separada
  int cont_algarismo = 0;
  int aux = n;
  while (aux > 0){
    if (aux >= 9 ){
      vetorNum[cont_algarismo] = aux; // quando chega no ultimo algarismo
    }
    vetorNum[cont_algarismo] = aux % 10; // colocar algarismos no vetor
    aux /= 10;
    cont_algarismo++;
  }

  //printf("\n%d algarismos no dogito %d\n", cont_algarismo, n);
  int controleIguais=0;
  for (int i = 0; i < cont_algarismo; i++){
    for (int j = i+1; j < cont_algarismo; j++){
      if (vetorNum[i] == vetorNum[j]){
        controleIguais ++;

        // ISSO AQUI QUE ESTÁ ERRADO !!!!! //
        printf("\nvetor[%d] = %d\nvetor[%d] = %d\n", i, vetorNum[i], j, vetorNum[j]);
      }
    }
  }
  if (controleIguais !=0 ) {
    (*count)++;
  }
  return conta_repetidos(n+1, m, vetorNum, count);
}




void mallocarVetorNum(int n, int **vetorNum){
  *vetorNum = (int*) malloc(sizeof(int) * 4);
  if (*vetorNum == NULL){
    printf("Espaço insuficiente\n");
    exit(1);
  }
}

