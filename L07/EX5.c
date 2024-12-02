#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prato {
    char nome[20];
    float preco;
};

int main(int argc, char *argv[]) {
    struct prato *cardapio = malloc(100 * sizeof(struct prato));

    int opcao = -1, count = 0;

    struct prato *pratos = malloc(100 * sizeof(struct prato));
    char *nameToBeDeleted = malloc(20 * sizeof(char));

    while(opcao != 0) {
        scanf("%d", &opcao);
        getchar();  // Consume the newline character

        if (opcao < 0 || opcao > 4) {
            printf("Erro: opcao invalida.\n");
        } else {
            switch (opcao) {
                case 1:
                    printf("Entro na opcao 1\n");

                    scanf("%s", cardapio[count].nome);  // Correctly read the name
                    getchar();

                    scanf("%f", &(cardapio[count].preco));  // Read price
                    getchar();

                    count++;
                    break;

                case 2:
                    printf("Entro na opcao 2\n");

                    scanf("%s", nameToBeDeleted);
                    getchar();

                    int indexToBeDeleted = -1;
                    for (int i = 0; i < 100; i++) {
                        if (strcmp(cardapio[i].nome, nameToBeDeleted) == 0) {
                            indexToBeDeleted = i;
                            break;
                        }
                    }

                    if (indexToBeDeleted == -1) {
                        printf("Erro: prato nao encontrado.\n");
                        break;
                    }

                    // Shift elements to remove the dish
                    for (int i = indexToBeDeleted; i < 99; i++) {
                        cardapio[i] = cardapio[i + 1];
                    }

                    break;

                case 3:
                    printf("Entro na opcao 3\n");

                    // Copy valid dishes from cardapio to pratos
                    count = 0;
                    for (int i = 0; i < 100; i++) {
                        if (cardapio[i].nome[0] == '\0') {  // Stop copying when empty dish is found
                            break;
                        }
                        pratos[count] = cardapio[i];
                        count++;  // Keep track of the number of valid dishes
                    }

                    // Sort pratos array alphabetically by name
                    for (int i = 0; i < count - 1; i++) {
                        for (int j = 0; j < count - i - 1; j++) {
                            if (strcmp(pratos[j].nome, pratos[j + 1].nome) > 0) {
                                struct prato temp = pratos[j];
                                pratos[j] = pratos[j + 1];
                                pratos[j + 1] = temp;
                            }
                        }
                    }

                    // Print sorted pratos
                    if (count == 0) {
                        printf("Erro: nenhum prato cadastrado.\n");
                    } else {
                        for (int i = 0; i < count; i++) {
                            printf("%-20s  %6.2f\n", pratos[i].nome, pratos[i].preco);
                        }
                    }

                    break;


                case 4:
                    printf("Entro na opcao 4\n");

                    // Copy valid dishes from cardapio to pratos
                    count = 0;
                    for (int i = 0; i < 100; i++) {
                        if (cardapio[i].nome[0] == '\0') {  // Stop copying when empty dish is found
                            break;
                        }
                        pratos[count] = cardapio[i];
                        count++;  // Keep track of the number of valid dishes
                    }

                    // Sort pratos array alphabetically by name
                    for (int i = 0; i < count - 1; i++) {
                        for (int j = 0; j < count - i - 1; j++) {
                            if (pratos[j].preco > pratos[j + 1].preco) {
                                struct prato temp = pratos[j];
                                pratos[j] = pratos[j + 1];
                                pratos[j + 1] = temp;
                            }
                        }
                    }

                    // Print sorted pratos
                    if (count == 0) {
                        printf("Erro: nenhum prato cadastrado.\n");
                    } else {
                        for (int i = 0; i < count; i++) {
                            printf("%-20s  %6.2f\n", pratos[i].nome, pratos[i].preco);
                        }
                    }

                    break;
            }
        }
    }

    free(cardapio);
    free(pratos);
    free(nameToBeDeleted);

    return 0;
}
