#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct turma {
    char nome[20];
    int notaFinal;
    int frequencia;
};

int main(int argc, char *argv[]) {

    int n;

    scanf("%d", &n);

    struct turma* alunos = (struct turma*)malloc(n * sizeof(struct turma));
    struct turma* inicio = alunos;

    getchar();

    for (int i = 0; i < n; i++) {
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        
        // Remove o '\n' do final do nome lido, se presente
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        scanf("%d", &(alunos[i].frequencia));

        getchar();

        scanf("%d", &(alunos[i].notaFinal));

        getchar();
    }

    int acimaCinco = 0, reprovadosFalta = 0;
    float media = 0; 

    while(alunos < inicio + n) {
        if (alunos->notaFinal > 5) {
            acimaCinco++;
        }

        if (alunos->frequencia < 75) {
            reprovadosFalta++;
        }

        media = media + alunos->notaFinal;
        alunos++;
    }

    printf("%d\n", acimaCinco);
    printf("%d\n", reprovadosFalta);
    printf("%.2f\n", media/n);

    free(inicio);

    return 0;
}