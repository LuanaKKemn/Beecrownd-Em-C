#include <stdio.h>
#include <string.h>
#include<stdlib.h>


int localizaPalavras(char *caso){
  int vetFinish[5];
  int j=0;
  for (int i=0; caso[i] != '\0'; i++){
    if (caso[i+1] != '\0'){
      if (caso[i] != '-' && caso[i+1] == '-'){ // termina a palavra //
        vetFinish[j] = i; // salva a posição da ultima letra da palavra
        j++; // atualiza j somente quando acaba a palavra
      }
    } // termina a string   
  }
  vetFinish[4] = strlen(caso); // adiciona no final a posição final da string
  return *vetFinish;
}



int verificaGH(int *vetor, char *caso){
  int j = 0;
  char vetMaius[6] = "COBOL";
  char vetMinus[6] = "cobol";
  
  int inicial = 0;
  int isTrue = 0;


  
  for (int k = 0; k<5; k++){ // percorre cada palavra
    
    int pos = vetor[j]; // o valor que esta no vetor é a posiçao no vetor caso
    isTrue = 0;

    
    for (int i = inicial; i<=pos; i++){ //percorre a palavra
      if (caso[i] == vetMaius[j] || caso[i] == vetMinus[j]){
        isTrue++;
        continue; // sai desse for 
      }
    } // se sair desse for sem achar nenhum retorna BUG
    if (isTrue == 0) {return 0;}
    
    inicial = pos+1;
    j++;
    // volta ao inicio 

    
   } return 1;
}


int main(void) {
  char *caso = (char*) malloc(sizeof(char)*50);

  scanf("%s", caso);

  int vetPos = localizaPalavras(caso);

  int resp = verificaGH(&vetPos, caso);

  resp == 1? printf("GRACE HOPPER"): printf("BUG");


  

  free(caso);
  return 0;
}