#include <stdio.h>

int main() {
  int n, i;

  scanf("%d", &n);

  int vetor[n], vetor_respostas[n];

  for (i = 0; i < n; i++){
    scanf("%d", &vetor[i]);
    vetor_respostas[i] = 0;
  }

  for (i = 0; i < n; i++){
    
    if (i == 0){
      if (vetor[i] == 1){
        vetor_respostas[i]++;
      }
      if (vetor[i+1] == 1){
        vetor_respostas[i]++;
      }
      
    } else if (i < n-1){
      if (vetor[i-1] == 1){
        vetor_respostas[i]++;
      }
      if (vetor[i] == 1){
        vetor_respostas[i]++;
      }
      if (vetor[i+1] == 1){
        vetor_respostas[i]++;
      }
    } else {
      if (vetor[i-1] == 1){
        vetor_respostas[i]++;
      }
      if (vetor[i] == 1){
        vetor_respostas[i]++;
      }
    }
  }

  for (i = 0; i < n; i++){
    printf("%d\n", vetor_respostas[i]);
  }

  return 0;
}