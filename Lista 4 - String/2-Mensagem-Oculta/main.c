#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50


void mallocarMatChar(int n, char ***mat){
  *mat = (char**) malloc (sizeof(char*)*n);
  if (!(*mat)) {
    printf("Espaço Insuficiente");
    exit(1);
  }
  for (int i=0; i<n; i++){
    (*mat)[i] = (char*) malloc(sizeof(char)*MAX_STRING_LENGTH);
    if (!(*mat)[i]){
      printf("Espaço Insuficiente");
      exit(1);
    }
  }
}

void freeMat(int n, char ***mat){
  for (int i=0; i<n; i++){
    free(mat[i]);
  }
  free(mat);
}

char* primeiraLetra(char *entrada){
  char *priLetra = (char*) malloc(sizeof(char*)*MAX_STRING_LENGTH);
  int j=0;
  
  for (int i=0; entrada[i] != '\0'; i++){
    if (i==0){
      if (entrada[i] != ' '){ // VERIFICA SE O 1º CHAR É UMA LETRA E COLOCA ELE NA RESPOSTA
        priLetra[j] = entrada[i];
        j++;
      }
    }
      
    else if (entrada[i+1] != '\0'){
      if (entrada[i] == ' ' && entrada[i+1] != ' '){
        priLetra[j] = entrada[i+1];
        j++;
      }
    }
  }
  priLetra[j] = '\0';  // adicionar o '\0' no final
  return priLetra;
}



int main(void) {
  int n;
  scanf("%d", &n);

  char **mensagemOc;
  mallocarMatChar(n, &mensagemOc);

  for (int i=0; i<n; i++){
    fgets(mensagemOc[i], MAX_STRING_LENGTH, stdin);
    mensagemOc[i][strcspn(mensagemOc[i], "\n")] = '\0';
  }

  for (int i=0; i<n; i++){
    char *secret = primeiraLetra(mensagemOc[i]);
    printf("%s", secret);
  }
  

  freeMat(n, &mensagemOc);
  return 0;
}