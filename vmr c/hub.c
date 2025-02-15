// hub incompleto teste


#include <stdio.h>
#include <stdlib.h>

int main(){
    int menu() {
    int escolha;
    printf("//- Gestão dos Correios -//\n");
    printf("Pressione o número correspondente à opção desejada.\n");
    printf("[1] Veículos\n");
    printf("[2] Entregas\n");
    printf("[3] Funcionários\n");
    printf("[4] Clientes\n");

    scanf("%d", &escolha);

    switch (escolha) {
        case 1: g_veiculos(); break;
        case 2: g_entregas(); break;
        case 3: g_funcionarios(); break;
        case 4: g_clientes(); break;
        default: printf("Opção inválida!\n");
    }
    return 0;
}
