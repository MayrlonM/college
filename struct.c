#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct aluno
    {
        char nome[50];
        int idade;
        float nota;
    };

    struct aluno aluno;

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno.idade);
    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno.nota);

    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Nota: %.2f\n", aluno.nota);

return 0;
}