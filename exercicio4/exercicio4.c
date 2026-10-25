#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto2D;

float calcular_distancia(Ponto2D p1, Ponto2D p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int main() {
    Ponto2D ponto1, ponto2;
    float distancia;

    printf("Coordenada x do Ponto 1: ");
    scanf("%f", &ponto1.x);
    printf("Coordenada y do Ponto 1: ");
    scanf("%f", &ponto1.y);

    printf("Coordenada x do Ponto 2: ");
    scanf("%f", &ponto2.x);
    printf("Coordenada y do Ponto 2: ");
    scanf("%f", &ponto2.y);

    distancia = calcular_distancia(ponto1, ponto2);

    printf("Distancia entre os pontos: %.2f\n", distancia);

return 0;
}