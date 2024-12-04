#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int digito;
    struct No* prox;
} No;

typedef struct lista {
    No* head;
} lista;

// Função para criar um novo nó
No* cria_no(int digito) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->digito = digito;
    novo->prox = NULL;
    return novo;
}

// Função para inserir um novo dígito no início da lista
void insere_inicio(lista* list, int digito) {
    No* novo = cria_no(digito);
    novo->prox = list->head;
    list->head = novo;
}

// Função para remover zeros à esquerda
void remove_zeros(lista* list) {
    while (list->head != NULL && list->head->digito == 0) {
        No* temp = list->head;
        list->head = list->head->prox;
        free(temp);
    }
}

// Função para imprimir a lista encadeada
void imprime_lista(lista* list) {
    No* temp = list->head;
    while (temp != NULL) {
        printf("%d", temp->digito);
        if (temp->prox != NULL) {
            printf(" -> ");
        }
        temp = temp->prox;
    }
    printf("\n");
}

// Função para realizar a subtração dos números representados por vetores
lista* subtrai_digitos(int* vetor1, int tamanho_vetor1, int* vetor2, int tamanho_vetor2) {
    int i = tamanho_vetor1 - 1;
    int j = tamanho_vetor2 - 1;
    int emprestimo = 0;

    lista* resultado = (lista*) malloc(sizeof(lista));
    if (resultado == NULL) {
        printf("Erro de alocação de memória para lista.\n");
        exit(1);
    }
    resultado->head = NULL;  // Inicializa a lista com head = NULL

    // Verifica qual número é maior e ajusta o sinal
    int negativo = 0;
    if (tamanho_vetor1 < tamanho_vetor2) {
        // Caso vetor2 seja maior que vetor1, invertemos a ordem e indicamos que o resultado será negativo
        int* temp_vetor = vetor1;
        vetor1 = vetor2;
        vetor2 = temp_vetor;
        int temp_tamanho = tamanho_vetor1;
        tamanho_vetor1 = tamanho_vetor2;
        tamanho_vetor2 = temp_tamanho;
        negativo = 1;
    } else if (tamanho_vetor1 == tamanho_vetor2) {
        int control = 0;

        while(control != tamanho_vetor1 - 1) {
            if(vetor1[control] > vetor2[control]) {
                break;
            }

            if(vetor1[control] < vetor2[control]) {
                int* temp_vetor = vetor1;
                vetor1 = vetor2;
                vetor2 = temp_vetor;
                int temp_tamanho = tamanho_vetor1;
                tamanho_vetor1 = tamanho_vetor2;
                tamanho_vetor2 = temp_tamanho;
                negativo = 1;
            }

            control++;
        }
    }

    // Realiza a subtração dígito a dígito
    while (i >= 0 || j >= 0) {
        int digito1 = (i >= 0) ? vetor1[i] : 0;
        int digito2 = (j >= 0) ? vetor2[j] : 0;

        // Subtração do dígito mais o possível empréstimo
        int subtracao = digito1 - digito2 - emprestimo;

        if (subtracao < 0) {
            subtracao += 10;  // Caso precise pegar emprestado

            emprestimo = 1;
        } else {
            emprestimo = 0;
        }

        // Inserir o dígito na lista encadeada
        insere_inicio(resultado, subtracao);

        // Decrementar os índices
        i--;
        j--;

    }

    // Remover zeros à esquerda
    remove_zeros(resultado);

    // Se o número for negativo, o primeiro dígito da lista deve ser negativo
    if (negativo && resultado != NULL) {
        resultado->head->digito = -(resultado->head->digito);
    }

    return resultado;
}

int main() {
    int vetor1[] = {1, 0, 0};  // Representa o número 100
    int vetor2[] = {1, 2, 3};  // Representa o número 123

    lista* resultado = subtrai_digitos(vetor1, 3, vetor2, 3);
    printf("Lista Encadeada (Resultado): ");
    imprime_lista(resultado);  // Saída esperada: -2 -> 3 (representa 23)

    // Libera a memória
    while (resultado->head != NULL) {
        No* temp = resultado->head;
        resultado->head = temp->prox;
        free(temp);
    }

    return 0;
}
