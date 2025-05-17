#include <stdio.h>
// DIAGONAL PRINCIPAL  => j==i
// DIAGONAL SECUNDÁRIA => j==(tam_max - i)

int main(){
  char opcao;
  double soma=0.0;
  int tam_matriz = 12;
  int i, j;
  int k, l;
  double matriz[tam_matriz][tam_matriz];

  scanf("%c", &opcao);
  
  for (i=0; i<tam_matriz; i++){
    for (j=0; j<tam_matriz; j++){
      //matriz[i][j] = 1.0;
      scanf("%lf", &matriz[i][j]);
    }
  }
  
  // ESCREVER MATRIZ NA TELA
  /*
  for (k=0; k<tam_matriz; k++){
    for (l=0; l<tam_matriz; l++){
      printf("%.1f ", matriz[k][l]);
    }
    printf("\n");
  }
  */ //- DEIXAR COMO COMENTARIO
  
  printf("\n");
  for (i = 1; i <= 10; i ++){
    if (i<=5) { for (j = 11; j>(11-i); j--) soma += matriz[i][j]; }
    else {for (j = 11; j>i; j--) soma += matriz[i][j]; }
  }

  if (opcao == 'S'){
    printf("%1.lf", soma);
  } else if (opcao == 'M'){
    printf("%.1lf", soma/((144-12-12)/4));
  }

  return 1;

}