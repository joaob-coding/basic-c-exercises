#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista encadeada
typedef struct Celula {
    int bit:4;
    struct Celula* prox;
} Celula;

// Função para criar um novo nó
Celula* cria_novo_no(int bit);

// Função para adicionar um bit ao inicio da lista
Celula* insere_no_inicio(Celula* lista, int bit);

// Função para somar dois números binários representados por listas encadeadas
Celula* soma_binario(Celula* num1, Celula* num2);

// Função para subtrair dois números binários representados por listas encadeadas
Celula* subtracao_binario(Celula* num1, Celula* num2);

// Função para imprimir a lista encadeada como um número binário
void imprime_lista(Celula* lista);

// Função para liberar a memória da lista
void free_lista(Celula* lista);

// Função lê arquivo (formato texto) para entrada dos números 
// e os insere nas listas encadeadas para cada número
void le_arquivo(const char *arquivo, Celula** numero1, Celula** numero2);

// Função principal que recebe o nome do arquivo texto como parâmetro
int main(int argc, char *argv[]) {
    if (argc < 2){
    	printf("Passe o nome do arquivo como parâmetro\n");
    	exit(1);
    } 	
    Celula* num1 = NULL; 
    Celula* num2 = NULL;
    
    // le o arquivo texto e insere nas listas os numeros binarios
    le_arquivo(argv[1], &num1, &num2);

    // Soma os números binários
    Celula* resultado_soma = soma_binario(num1, num2);
    // Subtrai os números binários
    Celula* resultado_sub = subtracao_binario(num1, num2);

    // Imprime o resultado
    printf("Resultado da soma: ");
    imprime_lista(resultado_soma);
    printf("\n");

    printf("Resultado da subtracao: ");
    imprime_lista(resultado_sub);
    printf("\n");

    // Libera a memória
    free_lista(num1);
    free_lista(num2);
    free_lista(resultado_soma);
    free_lista(resultado_sub);

    return 0;
}

// Função para criar um novo nó
Celula* cria_novo_no(int bit) {
    Celula* novoNo = (Celula*)malloc(sizeof(Celula));
    if (!novoNo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novoNo->bit = bit;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para adicionar um bit ao inicio da lista
Celula* insere_no_inicio(Celula* lista, int bit) {
    Celula* novoNo = cria_novo_no(bit);
    if (lista) 
        novoNo->prox = lista;
    return novoNo;
}

// Função para somar dois números binários representados por listas encadeadas
Celula* soma_binario(Celula* num1, Celula* num2) {
    Celula* resultado = NULL; //cria uma nova lista para armazenar o resultado
    int carry = 0;
    while (num1 || num2 || carry) {
        int soma = carry;

        if (num1) {
            soma += num1->bit;
            num1  = num1->prox;
        }
        if (num2) {
            soma += num2->bit;
            num2  = num2->prox;
        }
        resultado = insere_no_inicio(resultado, soma % 2);

        carry = soma / 2;
    }

    return resultado;
}

Celula* subtracao_binario(Celula* num1, Celula* num2) {
    Celula* resultado = NULL;
    int borrow = 0;

    while(num1 || num2 || borrow) {
        int sub = 0;

        if(num1) {
            sub = num1->bit;
            num1 = num1->prox;
        }

        if(num2) {
            sub -= num2->bit;
            num2 = num2->prox;
        }

        sub -= borrow;
        
        if(sub < 0) {
            sub += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }

        resultado = insere_no_inicio(resultado, sub % 2);
    }

    while (resultado != NULL && resultado->bit == 0) {
        Celula* temp = resultado;
        resultado = resultado->prox;
        free(temp);
    }

    return resultado;
}

// Função para imprimir a lista encadeada como um número binário
void imprime_lista(Celula* lista) {
    if (lista){
    	printf("%d", lista->bit);
    	if (lista->prox != NULL)
    		imprime_lista(lista->prox);
    	return;
    }
    else
    	printf("0\n");      	 
}

// Função para liberar a memória da lista
void free_lista(Celula* lista) {
    while (lista) {
        Celula* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Função lê arquivo (formato texto) para entrada dos números 
// e os insere nas listas encadeadas para cada número
void le_arquivo(const char *arquivo, Celula** numero1, Celula** numero2){
    FILE* file = fopen(arquivo, "r");
    char caractere;
    int  flag = 0;
    
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }  
     
    while (fscanf(file, "%c", &caractere) != EOF){ //le cada bit individualmente
    	if (caractere == ' ' || caractere == '\n')
    		flag = 1;
    	else {
    		if (flag == 0)  	
    		   *numero1 = insere_no_inicio(*numero1, caractere - '0'); 
    		else
    		   *numero2 = insere_no_inicio(*numero2, caractere - '0');
    	}
   }
   fclose(file);
}




