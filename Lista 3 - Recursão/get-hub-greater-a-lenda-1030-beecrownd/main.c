#include <stdio.h>

int recorrencia(int qtsSoldados, int qtsPulos);

int main ()
{

  int casos;
  int qtsInstancias;
  int qtsSoldados, qtsPulos;


  scanf("%d", &casos);

  int respostas[casos];
  int totalCasos = casos;
  
  qtsInstancias = 0;
  while (casos != 0){

    scanf("%d %d", &qtsSoldados, &qtsPulos);
    respostas[qtsInstancias] = recorrencia(qtsSoldados, qtsPulos) + 1;
    casos--;
    qtsInstancias++;
  }

  for (int i=0; i<totalCasos; i++){
    printf("Case %d: %d\n", i+1, respostas[i]);
  }  
    

  return 0;
}

int recorrencia(int qtsSoldados, int qtsPulos){

    int i, retorno;
    retorno = 0;

    for (i = 2; i <= qtsSoldados; i++)
        retorno = (retorno + qtsPulos) % i;

    return retorno;

}
