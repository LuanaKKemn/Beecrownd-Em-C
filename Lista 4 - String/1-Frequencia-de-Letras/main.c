#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mallocarMatrizes(char **mat, int n){
  mat = (char**) malloc (sizeof(char*)*n);
  if (mat == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }
  for (int i=0; i<n; i++){
    mat[i] = (char*) malloc(sizeof(char)*200);
    if (!mat[i]){
      printf("Espaço insuficiente");
      exit(1);
    }
  }
}

void mallocarMatrizINT(int **mat, int n){
  mat = (int**) malloc (sizeof(int*)*n);
  if (mat == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }
  for (int i=0; i<n; i++){
    mat[i] = (int*) malloc(sizeof(int)*200);
    if (!mat[i]){
      printf("Espaço insuficiente");
      exit(1);
    }
  }
}


int main(void) {
  int n;
  int i, j;

  printf("Digite n:");
  scanf("%d", &n);

  
  char **texto;

  char **respostas;

  int **numeros;

  mallocarMatrizes(texto, n);
  mallocarMatrizes(respostas, n);
  mallocarMatrizINT(numeros, n);
  
  for (int i=0; i<n; i++){
    scanf(" %s", texto[i]);
  }


  for (i=0; *texto[i] != '\0'; j++){      
    if (i == 0){
      *respostas[i] = numeros[i][i];
    }
    else {
      for (j=0; j == i; j++){
        if (*texto[i] == *respostas[j]){
          numeros[j] ++;
        }
      }
    }
  
  }


  
  return 0;
}