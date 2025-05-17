# include <stdio.h>

int main(){
  int n;
  int i;
  scanf("%d", &n);

  int vetor[n];
  int vetor_respostas[n];

  for (i=0; i<n; i++){
    scanf(" %d", &vetor[i]);
  }

  for (i=0; i<n; i++){
    if (i == n-1) {
      if (vetor[i]==vetor[i-1]) {
        if (vetor[i] == 1) {vetor_respostas[i] = 2;}
        else {vetor_respostas[i] = 0;}
      } else if (vetor[i] != vetor[i-1]){
        vetor[i] = 1;
      }
      break;
    }
    if      (vetor[i] == 0 && vetor[i+1] == 0) {vetor_respostas[i] = 0;}
    else if (vetor[i] != vetor[i+1]) {vetor_respostas[i] = 1;}
    else if (vetor[i] == 1 && vetor[i+1] == 1) {vetor_respostas[i] = 2;}
  }

  for (i=0; i<n; i++){
    printf("%d\n", vetor_respostas[i]);
  }
  

  return 1;
  
}