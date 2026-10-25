#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numero_conta;
    char titular[50];
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *c, float valor)
{
    if (valor > 0)
    {
        c->saldo += valor;
        printf("Depósito de R$ %.2f realizado com sucesso.\n", valor);
    }
    else
    {
        printf("Valor de depósito inválido.\n");
    }
}

int sacar(ContaBancaria *c, float valor)
{
    if (valor > 0 && c->saldo >= valor)
    {
        c->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
        return 1;
    }
    else
    {
        printf("Saque não realizado. Saldo insuficiente ou valor inválido.\n");
        return 0;
    }
}

int main()
{
    ContaBancaria minhaConta;
    float valor_deposito, valor_saque;

    printf("--- CADASTRO DA CONTA ---\n");
    printf("Número da conta: ");
    scanf("%d", &minhaConta.numero_conta);

    printf("Dono da conta: ");
    scanf("%s", minhaConta.titular);

    printf("Saldo inicial: ");
    scanf("%f", &minhaConta.saldo);

    printf("\n--- Estado Inicial ---\n");
    printf("Titular: %s | Conta: %d | Saldo: R$ %.2f\n", minhaConta.titular, minhaConta.numero_conta, minhaConta.saldo);

    printf("--- OPERAÇÃO DE DEPÓSITO ---\n");
    printf("Digite o valor para depositar: ");
    scanf("%f", &valor_deposito);
    depositar(&minhaConta, valor_deposito);
    printf("Saldo atualizado: R$ %.2f\n", minhaConta.saldo);

    printf("--- OPERAÇÃO DE SAQUE ---\n");
    printf("Digite o valor para sacar: ");
    scanf("%f", &valor_saque);

    int sucesso = sacar(&minhaConta, valor_saque);

    if (sucesso == 1)
    {
        printf("Saldo atualizado: R$ %.2f\n", minhaConta.saldo);
    }
    else
    {
        printf("Saldo mantido: R$ %.2f\n", minhaConta.saldo);
    }

    return 0;
}