#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int quantNum, aux, seed;

    printf("Digite a quantidade de números:\n");
    scanf("%d", &quantNum);

    printf("Digite o valor da seed:\n");
    scanf("%d", &seed);

    srand(seed);

    FILE *escrita = fopen("exemplo.txt", "w");

    for (int i = 0; i < quantNum; i++) {
        int x = rand() % 10;
        fprintf(escrita, "%d ", x);
    }

    fclose(escrita);

    FILE *leitura = fopen("exemplo.txt", "r");

    float soma;

    while(fscanf(leitura, "%d", &aux) != EOF) {
        printf("%d ", aux);
        soma = soma + aux;
    }

    printf("\n%.2f", soma / quantNum);

    fclose(leitura);

    return 0;
}