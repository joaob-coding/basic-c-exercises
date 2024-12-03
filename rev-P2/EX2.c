#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **create_matrix(int lines, char* string1, char* string2) {

    strcat(string1, string2);

    for(int i = 0; i < lines - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < lines; j++) {
            if(strcmp(&string1[j], &string1[min_index]) < 0) min_index = j;
        }

        if(min_index != i) {
            char aux = string1[i];
            string1[i] = string1[min_index];
            string1[min_index] = aux;
        }

    }

    char** matrix = malloc(lines * sizeof(char*));

    int positionOfString = 0;

    for (int i = 0; i < lines; i++) {
        matrix[i] = malloc(lines * sizeof(char));

        for (int j = 0; j < lines; j++) {
            if(positionOfString >= strlen(string1)) {
                matrix[i][j] = '-';
            } else {
                matrix[i][j] = string1[positionOfString];
                positionOfString++;
            }
        }
    }

    return matrix;

}

void printa_matrix(int size, char** string) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", string[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    char* string1 = malloc(100 * sizeof(char));
    char* string2 = malloc(100 * sizeof(char));

    printf("String 1: ");
    scanf("%s", string1);

    printf("String 2: ");
    scanf("%s", string2);

    int sizeOfString1 = strlen(string1);
    int sizeOfString2 = strlen(string2);

    if(sizeOfString1 > sizeOfString2) {
        char** matrix = create_matrix(sizeOfString1, string1, string2);
        printa_matrix(sizeOfString1, matrix);
        free(matrix);
    } else {
        char** matrix = create_matrix(sizeOfString2, string1, string2);
        printa_matrix(sizeOfString2, matrix);
        free(matrix);
    }

    free(string1);
    free(string2);

    return 0;

}