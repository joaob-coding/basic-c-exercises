#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

void ordena_vetor(int* vetor, int tamanho) {
    if(vetor != NULL) {
        for (int i = 0; i < tamanho - 1; i ++) {
            int max_index = i;
            for (int j = i + 1; j < tamanho; j++) {
                if(vetor[j] > vetor[max_index]) max_index = j;
            }

            if(max_index != i) {
                int aux = vetor[i];
                vetor[i] = vetor[max_index];
                vetor[max_index] = aux;
            }
        }
    }
}

void primos_ordenados(int* vetor, int tamanho, int** primos, int* tamanho_primos, int** outros_valores, int* tamanho_outros_valores) {

    *tamanho_primos = 0;
    *tamanho_outros_valores = 0;

    for (int i = 0; i < tamanho; i++) {
        int isPrimo = TRUE;
        for (int j = vetor[i] - 1; j > 1; j--) {
            if(vetor[i] % j == 0) {
                isPrimo = FALSE;
                break;
            }

        }

        if(isPrimo == TRUE) {
            if (*primos == NULL) {
                *primos = malloc(tamanho * sizeof(int));
            }

            (*primos)[*tamanho_primos] = vetor[i];
            (*tamanho_primos)++;
        } else {
            if(*outros_valores == NULL) {
                *outros_valores = malloc(tamanho * sizeof(int));
            }

            (*outros_valores)[*tamanho_outros_valores] = vetor[i];
            (*tamanho_outros_valores)++;
        }
    }

    ordena_vetor(*primos, *tamanho_primos);
    ordena_vetor(*outros_valores, *tamanho_outros_valores);

    if(*primos != NULL) {
        free(vetor);
    }

}

int main(int argc, char *argv[]) {

    int tamanhoVetOriginal;

    printf("Digite quantos elementos o vetor terá: ");
    scanf("%d", &tamanhoVetOriginal);

    int* vetOriginal = malloc(tamanhoVetOriginal * sizeof(int));

    for (int i = 0; i < tamanhoVetOriginal; i++) {
        printf("Digite o %d elemento: ", i + 1);
        scanf("%d", &(vetOriginal[i]));
    }

    int* primos = NULL;
    int* outros = NULL;
    int tamanho_primos, tamanho_outros = 0;

    printf("vetor original: \n");
    printf("[");
    for(int i = 0; i < tamanhoVetOriginal; i++) {
        printf("%d", vetOriginal[i]);
        if(i != tamanhoVetOriginal - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    primos_ordenados(vetOriginal, tamanhoVetOriginal, &primos, &tamanho_primos, &outros, &tamanho_outros);

    printf("vetor de primos: \n");
    printf("[");
    for(int i = 0; i < tamanho_primos; i++) {
        printf("%d", primos[i]);
        if(i != tamanho_primos - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("vetor de outros valores: \n");
    printf("[");
    for(int i = 0; i < tamanho_outros; i++) {
        printf("%d", outros[i]);
        if(i != tamanho_outros - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;

}