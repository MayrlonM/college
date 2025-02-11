#include <stdio.h>
#include <stdlib.h>

int main()
{
    //PROGRAMA 1: ponteiro para variável
    /*
        *p é o valor para onde p aponta
        p é o endereço para onde p aponta
        &c é o endereço de c
    */

    /*int c=10;

    int *p; // declaração de um ponteiro
    p = &c; // p aponta para o endereço na memória (usando o &) de c
    (*p)*10; // o valor para onde p aponta (c) é multiplicado por 10
    
    printf("endereco apontado por p: %p\n",p); // o P aponta para o endereço de c
    printf("valor apontado por p: %d\n",*p); //  o *P aponta para o valor de c
    */

    //PROGRAMA 2 : ponteiro
    /*
        **p é o valor para onde p aponta
        *p é o endereço para onde p aponta
        p é o endereço de onde p aponta
        &c é o endereço de c
    */

    /*int c=10, d=20;
    int *p,*p1;

    p = &c;
    p1 = &d;
    
    printf("%d\n",*p);
    printf("%d\n",*p1);
    */

    //PROGRAMA 3: ponteiros e arrays (ponteiros e vetores são conceitos muito próximos, pois vetores são ponteiros (apontam para o primeiro elemento do vetor))
    /*
        *p é equivalente a vet[0]
        vet é equivalente a &vet[0]
        vet[índice] é equivalente a *(p+índice)
        &vet[índice] é equivalente a (vet+índice)
    */

    /*
    int vet[5] = {1,2,8,4,5};
    int *p;
    p = vet; // p aponta para o primeiro elemento do vetor (vet[0])
    

    for(p=vet;p<vet+5;p++) // loop para percorrer o vetor utilizando ponteiro
        printf("%d\n",*p);
    */

    /*
    p = *(p+2); // p aponta para o terceiro elemento do vetor (vet[2]) / vet[índice] = *(p+índice)
    printf("%d\n",p);
    */

    //PROGRAMA 4: ponteiros e matrizes(arrays multidimensionais)
    /*
        *p é equivalente a mat[0][0]
        mat é equivalente a &mat[0][0]
        mat[linha][coluna] é equivalente a *(p+linha*coluna)
        &mat[linha][coluna] é equivalente a (mat+linha*coluna)
    */

    /*
    int mat[2][2] = {{1,2},{3,4}};
    int *p = &mat[0][0]; // p aponta para o primeiro elemento da matriz
    int i;
    for(i=0;i<4;i++)
        printf("%d\n", *(p+i)); // percorre a matriz utilizando ponteiro
    */

    //PROGRAMA 5: ponteiros e structs
    /*
        *p é equivalente a q.x
        p é equivalente a &q
        p->y é equivalente a q.y
    */

    /*
    struct ponto
    {
        int x,y;
    };

    struct ponto q;
    struct ponto *p;
    p = &q;
    (*p).x = 10;
    p->y = 20; // forma mais simples de acessar um campo de uma struct utilizando ponteiro
    printf("%d %d\n", (*p).x,p->y); // pode ser usado tanto o -> quanto o . para acessar um campo de uma struct utilizando ponteiro, ambos são equivalentes
    */

    //PROGRAMA 6: ponteiro para ponteiro
    /*
        **p2 é o valor para onde p2 aponta (o valor de x)
        *p2 é o endereço para onde p2 aponta (o endereço de x)
        p2 é o endereço de onde p2 aponta (o endereço de p1)
        &x é o endereço de x
    */

    int x = 10;
    int *p1 = &x;
    int **p2 = &p1; // p2 aponta para o endereço de p1

    printf("endereco em p2: %p\n",p2); // p2 aponta para o endereço de p1
    printf("conteudo em *p2: %p\n",*p2); // *p2 aponta para o endereço de x
    printf("conteudo em **p2: %d\n",**p2); // **p2 aponta para o valor de x

return 0;
}