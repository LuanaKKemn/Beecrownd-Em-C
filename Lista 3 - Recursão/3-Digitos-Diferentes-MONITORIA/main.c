#include <stdio.h>
#include <stdlib.h>

int *tranforma_em_vetor(int n, int *i){
  // ALOCA UM ESPAÇO GRANDE NO VETOR // 
  int *numero = (int *) malloc(sizeof(int) * 13),
      c = 0;
  while(n != 0){
     numero[c]  = n % 10;
     n /= 10;
     c++;
  }
  // REALOCA ESPAÇO DO VETOR // 
  numero = (int *) realloc(numero, sizeof(int) * c);
  *i = c;
  return numero;
}

int verrep(int *vet, int n){
  int contRepetidos = 0;
  
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(vet[i] == vet[j]){
        contRepetidos++;
      }
    }
  }
  if (contRepetidos > 0){
    return 1;
  } else {
    return 0; // --> NÃO EXISTEM NÚMEROS REPETIDOS
  }
}

int main(void) {

  // Entrada de dados
  int n, q;
  scanf("%d", &n);

  // Transforma em vetor
  int *vet = tranforma_em_vetor(n, &q);
  for(int i=0; i<q; i++)
   printf("%d ", vet[i]);

  // Saída de dados
  printf("\nExistem algarimos que se repetem no número %d? %s\n", n, (verrep(vet, q)) ? "não" : "sim");
  
  return 0;
}