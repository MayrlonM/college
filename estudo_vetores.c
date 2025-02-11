#include <stdio.h>
#include <stdlib.h>

// estudo de arrays 

int main(void) 
{
    float notas[5]; // vetor de notas
    int i;
    float sum=0;
    for(i=0;i<5;i++)
    {
        printf("nota do aluno %d: ",i+1); // pega a nota dos alunos
        scanf("%f", &notas[i]);
        sum = sum + notas[i]; // soma as notas
        printf("\n");
    }
    printf("soma das notas: %f\n",sum);
    printf("media das notas: %.2f\n",sum/5.0); // calcula a media


    for(i=0;i<5;i++)
        if (notas[i] >= 7)
        {
            printf("aluno %d aprovado\n",i+1);
        }
        else
        {
            printf("aluno %d reprovado\n",i+1);
        }

    
    
    
    return 0;
}

