#include <stdio.h>

void escreve_matriz(float *soma, float *media){
  int i, j;
  float matriz[12][12];
  for (i=0; i<12; i++){
    for (j=0; j<12; j++){
      scanf("%f", &matriz[i][j]);
      }
    }
  for (i=0; i<12; i++){
    for (j=i+1; j<12; j++){
      *soma = *soma + matriz[i][j];
    }
  }
  
  
}

int main(void) {
  char operacao;
  float soma = 0, media = 0;
  scanf("%c", &operacao);
  escreve_matriz(&soma, &media);

  if (operacao == 'S'){
    printf("%.1f\n", soma);
  } else if (operacao == 'M'){
    printf("%.1f\n", soma/66.0);
  }

  return 0;
}