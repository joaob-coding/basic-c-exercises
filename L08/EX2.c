#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct imagem {
    int n;
    int m;
    int **imageMatrix;
};

struct filtro {
    int m;
    int n;
    int **filtroMatrix;
};

unsigned int** aloca(int m, int n) {
    int i;
    int **M;

    M = (int**) malloc(m * sizeof(int));

    for (i = 0; i< n; i++) {
        M[i] = (int*) malloc(m * sizeof(int));
    }

    return M;
}

int convolution(int i, int j, short int mask[][3], int **image) {
    int p, q, aux;
    int nPixel = 0;
    i--; j--;
    aux = j;
    for (p = 0; p < 3; p++) {
        for (q = 0; q < 3; q++) {
            nPixel += image[i][j] * mask[p][q];
            j++;
        }
        j = aux;
        i++;
    }

    if (nPixel > 255) {
        nPixel = 255;
    } else if (nPixel < 0) {
        nPixel = 0;
    }

    return nPixel;
}

int main(int argc, char *argv[]) {

    return 0;
}