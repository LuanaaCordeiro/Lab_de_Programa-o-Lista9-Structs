#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char placa[10];
    int quilometragem;
    int status_revisao;
} Veiculo;

int contar_pendencias(Veiculo frota[], int n)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (frota[i].status_revisao == 0)
        {
            cont++;
        }
    }
    return cont;
}

void atualizar_quilometragem(Veiculo *v, int km_adicional)
{
    v->quilometragem += km_adicional;
    if (v->quilometragem > 10000)
    {
        v->status_revisao = 0;
    }
}

int main()
{
    Veiculo frota[4];
    int opcao;
    int indice;
    int km;
    opcao = 0; 
    
    for (int i = 0; i < 4; i++)
    {
        printf("--- Cadastro do Veiculo %d ---\n", i + 1);
        printf("Placa: ");
        scanf("%s", frota[i].placa);
        printf("Quilometragem: ");
        scanf("%d", &frota[i].quilometragem);
        printf("Status de Revisao (1 = Em Dia, 0 = Necessita Revisao): ");
        scanf("%d", &frota[i].status_revisao);
    }

   

    while (opcao != 3) {
        printf("\n--- Sistema de Gestao de Frota ---\n");
        printf("1. Atualizar quilometragem de um veiculo\n");
        printf("2. Contar pendencias de revisao\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Introduza o indice do veiculo (1 a 4): ");
            scanf("%d", &indice);
            if (indice >= 1 && indice <= 4) {
                printf("Quilometros adicionais: ");
                scanf("%d", &km);
                atualizar_quilometragem(&frota[indice - 1], km);
                printf("Veiculo atualizado! Quilometragem: %d | Status: %d\n", frota[indice - 1].quilometragem, frota[indice - 1].status_revisao);
            } else {
                printf("Indice invalido.\n");
            }
        } else if (opcao == 2) {
            int pendentes = contar_pendencias(frota, 4);
            printf("Total de veiculos que necessitam de revisao: %d\n", pendentes);
        }
    }

    return 0;
}