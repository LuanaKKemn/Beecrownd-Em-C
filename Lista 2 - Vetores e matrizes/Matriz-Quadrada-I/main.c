#include <stdio.h>

int escrever_matriz(int valorA, int *matriz[valorA][valorA]){
  int i, j;
  int a, b;
  int posicao_inicial = 0;
  int posicao_final = valorA - 1;

  for (i=0; i < valorA; i++){
    for (j=0; j < valorA; j++){
      for (a=0; a < (valorA/2); a++){
        int num = 1;
        *matriz[posicao_inicial][j] = num;
        *matriz[posicao_final][j] = num;
        *matriz[i][posicao_inicial] = num;
        *matriz[i][posicao_final] = num;
        num++;
        posicao_inicial++;
        posicao_final++;
      }
    }
  }
}

int main(void) {
  int valorA;
  int i, j;

  int posicao_meio, referencia;
  int endereco_meio;




  do {
    scanf("%d", &valorA);

    int matriz[valorA][valorA];

    for (i=0; i < valorA; i++){
      for (j=0; j < valorA; j++){
        matriz[i][j] = 0;
      }
    }

    escrever_matriz(valorA, &matriz[valorA][valorA]);

    if (valorA%2!=0){
      referencia = (valorA-3)/2;
      posicao_meio = 1 + (referencia);

      // if 3 => 1; if 5=>2 if 7=>3 if 9=>4
      endereco_meio = (valorA-1)/2;
      // na posição do meio o i == j
      matriz[endereco_meio][endereco_meio]=posicao_meio; 
    }

    for (i=0; i<valorA; i++){
      for (j=0; j<valorA; j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }

  } while (valorA < 0);

}
