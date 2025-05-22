#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int ehPalindromo(char *palavra, int inicio, int final){
  while (inicio<final){
    if (palavra[inicio] != palavra[final]){
      return 0;
    }    
      final --;
      inicio++;
  }
  return 1;
}


int palindrominhos(char *palavra, int n, int d) {
    int maxValor = 0;

    for (int p = 1; p <= n; p++) {
        int valorAtual = 0;
        for (int i = 0; i <= n - p; i += d) {
            if (i + p - 1 < n && ehPalindromo(palavra, i, i + p - 1)) {
                valorAtual += p;
            }
        }
        if (valorAtual > maxValor) {
            maxValor = valorAtual;
        }
    }

    return maxValor;
}


int main(void) {
  int n, d;

  while (1) {
    scanf("%d %d", &n, &d);
    if (n == 0 && d ==0){
      break;
    }

    char *palavra = (char*) malloc(sizeof(char)*(n+1));

    scanf("%s", palavra);

    int result = palindrominhos(palavra, n, d);

    printf("%d\n", result);
    
    
    free(palavra);

  } 
  
 

  return 0;
}