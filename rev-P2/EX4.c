#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char caractere;
    struct No* proximo;
} No;

No* cria_no(char caractere) {
    No* novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro na alocação de um novo nó");
        exit(-1);
    }

    novo->caractere = caractere;
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

void printa_string(No* string) {
    No* aux = string;
    printf("lista ->");
    while(aux != NULL) {
        printf(" %c ->", aux->caractere);
        aux = aux->proximo;
    }
    printf(" NULL\n");
}

char* strip_string(No* string, int* tamanho_string) {
    No* aux = string;

    // Aloca memória para a string convertida
    char* string_convertida = malloc(*tamanho_string * sizeof(char));

    int track = 0;

    // Percorre a lista encadeada
    while (aux != NULL) {
        // Copia caracteres válidos para a string_convertida
        if (aux->caractere != ' ' && aux->caractere != '\0') {
            string_convertida[track] = aux->caractere;
            track++;
        }

        // Se o próximo caractere for espaço ou '\0', removemos esse nó
        if (aux->proximo != NULL && (aux->proximo->caractere == ' ' || aux->proximo->caractere == '\0')) {
            No* temp = aux->proximo;
            aux->proximo = aux->proximo->proximo; // Avança aux para o próximo nó válido
            aux = aux->proximo;
            free(temp); // Libera o nó removido
            *tamanho_string = *tamanho_string - 1; // Decrementa o tamanho da string
        } else {
            aux = aux->proximo; // Avança normalmente para o próximo nó
        }
    }

    // Retorna a string convertida
    return string_convertida;
}

int checa_palindromo(No* string, int tamanho_string) {
    No* aux = string;

    char* string_convertida = strip_string(aux, &tamanho_string);

    for (int i = 0; i < tamanho_string / 2; i++) {

        if(string_convertida[i] != string_convertida[tamanho_string - 1 - i]) {
            free(string_convertida);
            return 1; // Não é palíndromo
        }
    }

    free(string_convertida);
    return 0; // É palíndromo
}

int main(int argc, char *argv[]) {
    char *string = malloc(50 * sizeof(char));

    printf("Palavra: ");
    fgets(string, 50, stdin);

    int tamanho_string = strlen(string);
    if (string[tamanho_string - 1] == '\n') {
        string[tamanho_string - 1] = '\0';  // Remove o caractere de nova linha
        tamanho_string--; // Ajusta o tamanho
    }

    No* lista_encadeada = converte_string_para_lista_encadeada(string, tamanho_string);
    printa_string(lista_encadeada);

    int palindromo = checa_palindromo(lista_encadeada, tamanho_string);

    if(palindromo == 1) {
        printf("Não é palíndromo");
    } else {
        printf("É palíndromo");
    }

    // Libera a memória
    free(lista_encadeada);
    free(string);

    return 0;
}
