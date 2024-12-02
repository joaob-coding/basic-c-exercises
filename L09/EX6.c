#include <stdio.h>

int estaOrdenado(int v[], int s) {

    for (int i = 0; i < s - 1; i++) {
        if(v[i] > v[i + 1]) {
            return 0;
        }
    }

    return 1;
   
}

void read(int vetor[], int n) {
  for (int i = 0; i < n; i++) {
      printf("Digite o valor: ");
      scanf("%d", &vetor[i]);
  }
}

void show(int vetor[], int s) {
  for (int i = 0; i < s; i++)
    printf("%d ", vetor[i]);
  printf("\n");
}

int main() {
  int n, chave;
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &n);
  int vetor[n];
  read(vetor, n);
  printf("Vetor digitado:\n");
  show(vetor, n);
  int r = estaOrdenado(vetor, n);
  if (r == 0) {
      printf("O vetor não está ordenado.\n");
  } else if (r == 1) {
      printf("O vetor está ordenado.\n");
  }
  return 0;
}