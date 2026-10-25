#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int codigo;
    char nome[50];
    float preco;
    int quantidade;

} PRODUTO;

PRODUTO criar_produto(int cod, char nome[], float preco, int qtd)
{
    PRODUTO p;

    p.codigo = cod;
    strcpy(p.nome, nome);
    p.preco = preco;
    p.quantidade = qtd;

    return p;
}

void exibir_produto(PRODUTO p)
{

    float total = p.preco * p.quantidade;

    printf("O codigo do produto eh: %d\n", p.codigo);
    printf("O nome do produto eh: %s\n", p.nome);
    printf("O preco do produto eh: %.2f\n", p.preco);
    printf("A quantidade do produto eh: %d\n", p.quantidade);

    printf("O total arrecadado foi: %f", total);
}

int main()
{

    int cod;
    char nome[50];
    float preco;
    int qtd;

    printf("----------DIGITE OS CAMPOS----------\n");
    printf("Codigo: ");
    scanf("%d", &cod);

    printf("Nome: ");
    scanf("%s", nome);

    printf("Preco: ");
    scanf("%f", &preco);

    printf("Quantidade: ");
    scanf("%d", &qtd);

    PRODUTO p = criar_produto(cod, nome, preco, qtd);
    exibir_produto(p);

    return 0;
}