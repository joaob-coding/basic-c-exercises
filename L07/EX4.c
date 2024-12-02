#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union value {
    int result;
    int quocAndResto[2];
};

int main(int argc, char *argv[]) {

    union value resultadoOperacao;
    int opcao, x, y;

    printf("Digite os operandos x e y\n");
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Digite a operação: 1 - Adição, 2 - Subtração, 3 - Multiplicação, 4 - Divisão\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            resultadoOperacao.result = x + y;
            printf("Resultado: %d", resultadoOperacao.result);

            break;
        case 2:
            resultadoOperacao.result = x - y;
            printf("Resultado: %d", resultadoOperacao.result);

            break;
        case 3:
            resultadoOperacao.result = x * y;
            printf("Resultado: %d", resultadoOperacao.result);

            break;
        case 4:
            if(y == 0) {
                printf("Erro");
                break;
            }

            resultadoOperacao.quocAndResto[0] = x / y;
            resultadoOperacao.quocAndResto[1] = x % y;

            printf("Resultado: %d, %d", resultadoOperacao.quocAndResto[0], resultadoOperacao.quocAndResto[1]);

            break;
    }

    return 0;
}