#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char modelo[30];
    int ano;
    float preco;
} Carro;

void buscar_por_preco(Carro frota[], int n, float preco_max)
{
    int encontrou = 0;
    for (int i = 0; i < n; i++)
    {
        if (frota[i].preco <= preco_max)
        {
            printf("Modelo: %s | Ano: %d\n", frota[i].modelo, frota[i].ano);
            encontrou = 1;
        }
    }
    if (encontrou == 0)
    {
        printf("Nenhum carro encontrado nesta faixa de preco.\n");
    }
}

int main()
{
    Carro frota[6];
    float preco_busca;

    for (int i = 0; i < 6; i++)
    {
        printf("--- Carro %d ---\n", i + 1);
        printf("Modelo: ");
        scanf("%s", frota[i].modelo);
        printf("Ano: ");
        scanf("%d", &frota[i].ano);
        printf("Preco: ");
        scanf("%f", &frota[i].preco);
    }

    printf("Digite o preco maximo para busca: ");
    scanf("%f", &preco_busca);

    printf("--- Resultados da Busca ---\n");
    buscar_por_preco(frota, 6, preco_busca);

    return 0;
}