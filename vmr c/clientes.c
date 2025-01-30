#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define FILE_NAME "clientes.txt"


// Função para gerar um ID único aleatório
int gerarID() {
    return rand() % 10000; // Gera um ID aleatório entre 0 e 9999
}

int main() {
    char nome[MAX_LENGTH];
    char cidade[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    int id;

    // Inicializando o gerador de números aleatórios
    srand(time(NULL));

    // Coletando informações do cliente
    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove a nova linha

    printf("Digite a cidade do cliente: ");
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = 0; // Remove a nova linha

    printf("Digite o endereço do cliente: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = 0; // Remove a nova linha

    // Gerando um ID único
    id = gerarID();

    // Armazenando os dados em um arquivo
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", FILE_NAME);
        return 1;
    }

    fprintf(file, "ID: %d\nNome: %s\nCidade: %s\nEndereco: %s\n\n", id, nome, cidade, endereco);
    fclose(file);

    printf("Dados do cliente armazenados com sucesso!\n");
    return 0;
}