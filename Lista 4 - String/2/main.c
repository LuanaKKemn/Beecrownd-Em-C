#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){

  char texto[51], resultado[51], lixo;
  unsigned short i, j;
  unsigned casos;

  scanf("%u", &casos);
  scanf("%c", &lixo); 

  while (casos--) {

    scanf("%[^\n]", texto);
    scanf("%c", &lixo);

    i = 0;
    j = 0;

    while (texto[i]) {
      if (texto[i] == ' ')
        i++;

      else
      {
        resultado[j++] = texto[i++];
        while (isalpha(texto[i]))
           i++;	
      }	
    }
    resultado[j] = '\0';
    printf("%s\n", resultado);
    memset(resultado, 0, sizeof(resultado));
  }
  return 0;
}