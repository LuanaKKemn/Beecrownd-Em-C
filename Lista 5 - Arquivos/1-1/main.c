#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://judge.beecrowd.com/pt/problems/view/1244

// Struct de palavras
typedef struct palavra{
  char *p;
  int n;
} PA;

// Estrutura do nó
typedef struct node{
  PA dado;
  struct node *prox;
} NO;

// Cria um nó isolado
NO *cria(char *v){
  NO *no = (NO *) malloc(sizeof(NO));
  no->dado.p = (char *) malloc(sizeof(char) * 51);
  no->dado.n = strlen(v);
  strcpy(no->dado.p, v);
  no->prox = NULL;
  return no;
}
// Insere um elemento no final da lista
NO *ins(NO *l, char *v){
  NO *no = cria(v);
  if(!l) return no;
  NO *a = l;
  while(a->prox)
    a = a->prox; 
  a->prox = no;
  return l;
}
void imp(NO *l){
  while(l){
    printf("%s%s", l->dado.p, (l->prox) ? " " : "");
    l = l->prox;
  }
}
void lib(NO *l){
  NO *r;
  while(l){
    r = l;
    l = l->prox;
    free(r->dado.p);
    free(r);
  }
}
void libr(NO *l){
  if(l->prox) libr(l->prox);
  free(l);
}

// Dado um nó procure o anterior na lista
NO *procura_anterior(NO *l, NO *r){
  while(l->prox != r)
    l = l->prox;
  return l;
}

// Separa as palavras da frase e transforma em uma lista      
NO *string2lista(char *frase){
  char palavra[51];
  NO *lista_palavras = NULL;

  int i = 0;
  while(frase[i] == ' ') i++;

  // condição de parada
  while(i < strlen(frase)){

    // Lê a string e coloca dentro de palavra
    sscanf(&frase[i], "%s", palavra);
    i += strlen(palavra);
  
    // Coloca a palavra na lista
    lista_palavras = ins(lista_palavras, palavra);

    // Procura o proximo caractere que não seja ' '
    while(frase[i] == ' ') i++;
  }

  return lista_palavras;
}

// Selection sort
NO *selection_sort(NO *l){
  NO *i = l, *maior, *j, *anterior = NULL;
  while(i){
    maior = i;
    j = i->prox;
    while(j){
      if(maior->dado.n < j->dado.n){
        maior = j;
      }
      j = j->prox;
    }
    if(maior != i){
      NO *no = cria(i->dado.p);
      no->prox = i->prox;
      i->prox = no;
      i->dado = maior->dado;
      anterior = procura_anterior(l, maior);
      anterior->prox = maior->prox;
      maior->prox = NULL;
      lib(maior);
    }
    i = i->prox;
  }
  return l;
}

int main(void){
  char frase[51];

  // Entrada de dados
  int n;
  scanf("%d", &n);

  // LOOP
  for(int i=0; i<n; i++){

    // Entrada de dados
    scanf(" %50[^\n]", frase);

    // Processamento

    // Separa a frase em um lista de palavras
    NO *palavras = string2lista(frase);

    // Ordena as palavras
    palavras = selection_sort(palavras);
    
    // Saída de dados
    imp(palavras);

    lib(palavras);
  }

  return 0;
}

// 4
// Top Coder comp Wedn at midnight
// one three five
// I love Cpp
// sj a sa df r e w f d s a v c x z sd fd

// midnight Coder comp Wedn Top at
// three five one
// love Cpp I
// sj sa df sd fd a r e w f d s a v c x z



// sj sa df sd a r e w f d s a v c x z fd