#include <stdio.h>
#include <stdlib.h>

struct Elemento {
  int valor;
  struct Elemento *proximo;
};
typedef struct Elemento Elemento;

Elemento *insere(Elemento *lista, int value) {
  Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
  novo->proximo = NULL;
  novo->valor = value;
  Elemento *aux = lista;
  if (aux == NULL) {
    lista = novo;
  } else {
    while (aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
  return lista;
}

void consulta(Elemento *lista) {
  if (lista == NULL)
      printf("Lista vazia!!\n");
  else {
    for (Elemento *e = lista; e != NULL; e = e->proximo) {
       printf("%d ", e->valor);
    }
    printf("\n");
  }
}

Elemento *removeUltimo(Elemento *lista) {

    if (lista == NULL) {
        return NULL;
    }

    if (lista->proximo == NULL) {
        free(lista);
        return NULL;
    }

    Elemento *aux = lista;

    while(aux->proximo != NULL && aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }

    free(aux->proximo);
    aux->proximo = NULL;
    return lista;

}

int main() {
  int n1;
  printf("Quantidade de Elementos: \n");
  scanf("%d", &n1);
  Elemento *lista = NULL; // Cria lista encadeada

  for (int i = 0; i < n1; i++) {
    printf("Número a ser inserido: ");
    int v1;
    scanf("%d", &v1);
    lista = insere(lista, v1);
  }
  printf("Consulta: \n");
  consulta(lista);
  printf("Remove último elemento...\n");
  removeUltimo(lista);
  printf("Consulta: \n");
  consulta(lista);
  return 0;
}