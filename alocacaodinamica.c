#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    int x,y;
};

int main()

{
    //MALLOC (aloca memória)
//sizeof retorna o tamanho em bytes de um tipo de dado
/*
    printf("tamanho do char: %d\n",sizeof(char));//1
    printf("tamanho do int: %d \n",sizeof(int));//4
    printf("tamanho do float: %d \n",sizeof(float));//4
    printf("tamanho do ponto: %d \n",sizeof(struct ponto));//8 (2*4(inteiros))-> x e y
*/
/*
    int *p;
    p = (int *) malloc(5*sizeof(int));
    if (p == NULL)
    {
        printf("erro de alocacao, memoria insuficiente\n");
        system("pause");
        exit(1);
    }
    int i;
    for(i=0;i<5;i++)
    {
        printf("digite o valor da posicao %d: ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("valor da posicao %d: %d\n",i+1,p[i]);
    }
*/
    //CALLOC (inicializa a memória alocada com 0)
    int *p;
    p = (int *) calloc(50,sizeof(int));
    if (p == NULL)
    {
        printf("erro de alocacao, memoria insuficiente\n");
        system("pause");
        exit(1);
    }
    

return 0;
}