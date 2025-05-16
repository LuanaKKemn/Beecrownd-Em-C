#include <stdio.h>
// DESISTI DESSE DAQUI E RECOMECEI


void escreve_matriz(float *soma, int *contadormatriz){
  int i, j;
  int num_mat = 4;
  float matriz[num_mat][num_mat];
  for (i=0; i<num_mat; i++){
    for (j=0; j<num_mat; j++){
      matriz[i][j] = 4.4;
      printf("%.1f ", matriz[i][j]);
      //scanf("%f", &matriz[i][j]);
    //printf("matriz[%d][%d]", i, j);
    }
  }
  printf("Matriz \n%f", &matriz[num_mat][num_mat]);
  for (i=1; i<11; i++){
    if (i>=5){
      for (j = 11; j > 11-i; j--){
        *soma += matriz[i][j];
        (*contadormatriz)++;
      }
    } else {
      for (j = 11; j > i; j--){
        *soma += matriz[i][j];
        (*contadormatriz)++;
      }
    }
      
  }

}

int main(void){
  char opcao;
  float soma = 0;
  int contadormatriz = 0;
  scanf("%c", &opcao);

  escreve_matriz(&soma, &contadormatriz);

  if (opcao == 'S'){
    printf("%.1f\n", soma);
  } else if (opcao == 'M'){
    printf("%.1f\n", soma/contadormatriz);
  }
}