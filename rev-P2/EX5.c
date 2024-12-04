#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char caractere;
    struct No* proximo;
} No;

No* cria_no(char value) {
    No* novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro na alocação de um novo nó");
        exit(-1);
    }

    novo->caractere = value;
    novo->proximo = NULL;

    return novo;
}

No* converte_string_para_lista_encadeada(char string[], int tamanho_string) {
    No* head = cria_no(string[0]);
    No* aux = head;

    for(int i = 1; i < tamanho_string; i++) {
        aux->proximo = cria_no(string[i]);
        aux = aux->proximo;
    }

    return head;
}

int compara_palavras(No* palavra1, No* palavra2) {
    No* aux1 = palavra1;
    No* aux2 = palavra2;

    while(aux1 != NULL || aux2 != NULL) {
        if(aux1 == NULL && aux2 != NULL) {
            return -1;
        } else if(aux1 != NULL && aux2 == NULL) {
            return 1;
        }

        int comparison = strcmp(&(aux1->caractere), &(aux2->caractere));

        if(comparison > 0) {
            return 1;
        } else if(comparison < 0) {
            return -1;
        }

        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }

    return 0;
}

void printa_lista(No* lista) {
    No* aux = lista;

    while(aux != NULL) {
        printf("%c -> ", aux->caractere);
        aux = aux->proximo;
    }

    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    char *string1 = malloc(50 * sizeof(char));
    char *string2 = malloc(50 * sizeof(char));

    printf("Palavra 1: ");
    fgets(string1, 50, stdin);

    printf("Palavra 2: ");
    fgets(string2, 50, stdin);

    int tamanho_string1 = strlen(string1);
    if (string1[tamanho_string1 - 1] == '\n') {
        string1[tamanho_string1 - 1] = '\0';  // Remove o caractere de nova linha
        tamanho_string1--; // Ajusta o tamanho
    }

    int tamanho_string2 = strlen(string2);
    if(string2[tamanho_string2 - 1] == '\n') {
        string2[tamanho_string2 - 1] = '\0';
        tamanho_string2--;
    }

    No* lista_encadeada1 = converte_string_para_lista_encadeada(string1, tamanho_string1);
    printf("palavra 1: ");
    printa_lista(lista_encadeada1);

    No* lista_encadeada2 = converte_string_para_lista_encadeada(string2, tamanho_string2);
    printf("palavra 2: ");
    printa_lista(lista_encadeada2);

    int result = compara_palavras(lista_encadeada1, lista_encadeada2);

    switch(result) {
        case 0:
            printf("As palavras são iguais.");
            break;
        case -1:
            printf("A palavra (%s) é menor lexicograficamente que a palavra (%s).", string1, string2);
            break;
        case 1:
            printf("A palavra (%s) é maior lexicograficamente que a palavra (%s).", string1, string2);
            break;
    }

    return 0;

}