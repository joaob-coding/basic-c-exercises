#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coordenada {
    int x, y, z;
};

void swap_points(int* point, int* swapPoint) {
    int temp;

    temp = *point;
    *point = *swapPoint;
    *swapPoint = temp;
}

void swap (struct coordenada* p1, struct coordenada* p2) {

    int tempx, tempy, tempz;

    swap_points(&(p1->x), &(p2->x));
    swap_points(&(p1->y), &(p2->y));
    swap_points(&(p1->z), &(p2->z));

}

void show_coordinates(struct coordenada* p1, struct coordenada* p2) {

    printf("P1 (%d,%d,%d)", p1->x, p1->y, p1->z);
    printf(" ");
    printf("P2 (%d,%d,%d)", p2->x, p2->y, p2->z);

}

void read_coordinates(struct coordenada* point) {
    scanf("%d", &(point->x));
    scanf("%d", &(point->y));
    scanf("%d", &(point->z));
}

int main(int argc, char *argv[]) {

    struct coordenada p1, p2;

    printf("Digite x, y, z de P1:\n");
    read_coordinates(&p1);
    printf("\nDigite x, y, z de P2:\n");
    read_coordinates(&p2);

    printf("\nANTES\n");
    show_coordinates(&p1, &p2);

    swap(&p1, &p2);

    printf("\nDEPOIS\n");
    show_coordinates(&p1, &p2);

    return 0;
}