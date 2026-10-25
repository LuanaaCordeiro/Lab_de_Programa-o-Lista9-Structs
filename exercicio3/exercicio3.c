#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int matricula;
    char nome[50];
    float media;
} Aluno;

void ler_turma(Aluno turma[], int n) {
    
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &turma[i].matricula);
        printf("Nome: ");
        scanf("%s", turma[i].nome);
        printf("Media: ");
        scanf("%f", &turma[i].media);
    }
}

Aluno aluno_maior_media(Aluno turma[], int n) {
    Aluno campeao = turma[0];
    for (int i = 1; i < n; i++) {
        if (turma[i].media > campeao.media) {
            campeao = turma[i];
        }
    }
    return campeao;
}

int main() {
    Aluno turma[5];
    
    printf("Cadastro da Turma (5 alunos)\n");
    ler_turma(turma, 5);
    
    Aluno destaque = aluno_maior_media(turma, 5);
    
    printf("\n--- Aluno Campeao ---\n");
    printf("Nome: %s\n", destaque.nome);
    printf("Nota: %.2f\n", destaque.media);

return 0;
}