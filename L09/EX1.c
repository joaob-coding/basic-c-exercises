#include <stdio.h>
#include <stdlib.h>

struct Elemento {
  int valor;
  struct Elemento *proximo;
};
typedef struct Elemento Elemento;

struct Pilha {
  struct Elemento *topo; /*aponta para o elemento que esta no topo da pilha*/
};
typedef struct Pilha Pilha;

Elemento *aux;

Pilha *cria() {
  Pilha *pi = (Pilha *)malloc(
      sizeof(Pilha)); // alocação do ponteiro pi para controlar a pilha
  pi->topo = NULL;
  return pi;
}

void insere(Pilha *pi) {

    int insert;

    printf("Número a ser inserido: ");
    scanf("%d", &insert);

    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = insert;
    novo->proximo = pi->topo;

    pi->topo = novo;
 
}


void consulta(Pilha *pi) {
  if (pi->topo == NULL) {
    printf("Pilha Vazia!!\n");
  } else {
    aux = pi->topo;
    do {
      printf("%d\n", aux->valor);
      aux = aux->proximo;
    } while (aux != NULL);
  }
}


int main() {
  Pilha *pi = cria();
  int e;
  printf("Quantidade a ser inserida: \n");
  scanf("%d",&e);
  for (int i = 0; i < e; i++) {
      insere(pi);
  }
  printf("Consulta: \n");
  consulta(pi);
  return 0;
}