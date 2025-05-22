#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void matStr(char ***palavras){
  **palavras = (char*) malloc (sizeof(char*)*30);
  if (!(*palavras)){
    printf("Espaço Insuficiente");
    exit(1);
  }
  for (int i=0; i<10; i++){
    (*palavras)[i] = (char*) malloc(sizeof(char*)*30);
    if (!(*palavras)[i]){
      printf("Espaço Insuficiente");
      exit(1);
    }
  }
}

// void realoocarMatStr(char ***palavras, int q){
//   *palavras = (char*) realloc(palavras, q);
  
// }

void freeMatStr(char ***palavras, int q){
  for (int i=0; i<q; i++){
    free(palavras[i]);
  }
  free(palavras);
}



void removerfinal(char ***palavras, int q){
  for (int i=0; i<q; i++){ // cada linha
    char *stringAUX = (char*) malloc(sizeof(char)*30);
    
    for (int j=0; (*palavras)[i][j] != '\0'; j++){ // cada palavra
      if (j==0){
        (*palavras)[i][j] = stringAUX[j];
      } else{
        for (int k=0; (stringAUX[k] != '\0'); k++){
           if ((*palavras)[i][j] != stringAUX[k])
             stringAUX[j] = (*(palavras)[i][j]);
        }
      }
    }strcpy(((*palavras)[i]), stringAUX);
    free(stringAUX);
  }
}

//////////////////////////////////////////////////////////////////
int main(void) {
  char **palavras;

  matStr(&palavras);

  FILE *arq = fopen("arquivo.txt", "r");
  if (!arq){
    printf("Não foi possivel abrir o arquivo");
    exit(1);
  }

  
  int q=0;
  int i =0;
  while (arq){
    fscanf(arq, " %s", palavras[i]);
    i++;
    q++;
  }

  
  free(palavras, q);
  fclose(arq);
  return 0;
}