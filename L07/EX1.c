#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char nome[20];
    int idade;
    float altura;
    float peso;
};

void showStruct(struct user pessoa) {
    
    printf("\nO nome é: %s\n", pessoa.nome);
    printf("A idade é: %d \n", pessoa.idade);
    printf("A altura é: %.2f \n", pessoa.altura);
    printf("O peso é: %.2f \n", pessoa.peso);
    
}

int main(int argc, char* argv) {
    
    struct user user1 = {"João Silva", 30, 1.65, 75.50}, user2;
    
    printf("Digite o nome: ");
    fgets(user2.nome, sizeof(user2.nome), stdin);
    
    printf("Digite a idade: ");
    scanf("%d", &(user2.idade));
    
    printf("Digite a altura: ");
    scanf("%f", &(user2.altura));
    
    printf("Digite o peso: ");
    scanf("%f", &(user2.peso));
    
    showStruct(user1);
    showStruct(user2);
    
    return 0;
}