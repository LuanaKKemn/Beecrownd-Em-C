#include <stdio.h>

int main() {
  char opcao;
  double matriz[12][12], soma = 0, media = 0;
  int i, j, k = 0;

  scanf("%c", &opcao);

  for (i = 0; i < 12; i++){
    for (j = 0; j < 12; j++){
      scanf("%lf", &matriz[i][j]);
    }
  }

  for (i = 0; i < 12; i++){
    for (j = 0; j < 12; j++){
      if (i < j && i > 12 -j - 1){
        soma += matriz[i][j];
        k++;
      }
    }
  }

  media = soma / k;

  if (opcao == 'S'){
    printf("%.1lf\n", soma);
  } else if (opcao == 'M'){
    printf("%.1lf\n", media);
  }

  return 0;
}