#include <stdio.h>
#include <string.h>

int digitosRepetidos(int num){
  int digitos[10] = {0};
  while (num > 0){
    int digito = num % 10;
    if (digitos[digito] == 1)
      return 1;

    digitos[digito]++;
    num /= 10;
  }  
  return 0;
}

int main() {
  int n, m, contador = 0;
  scanf("%d %d", &n, &m);
  
  for (int i = n; i <= m; i++){
    if (! digitosRepetidos(i))
    contador ++;
  }
  printf("%d\n", contador);
  
  return 0;
}