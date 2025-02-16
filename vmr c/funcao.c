#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100
#define MAX_ENTREGAS 100
#define MAX_FUNCIONARIOS 100
#define MAX_CLIENTES 100

// Definição das estruturas
typedef struct {
    int id;
    char tipo[20];
    float capacidadeCarga;
    char status[10]; // "livre" ou "ocupado"
} Veiculo;

typedef struct {
    int id;
    char origem[100];
    char destino[100];
    float tempoEstimado; // em horas
} Entrega;

typedef struct {
    int id;
    char nome[100];
} Funcionario;

typedef struct {
    int id;
    char nome[100];
    char endereco[200];
    char tipoServico[20]; // "economico", "padrao", "premium"
} Cliente;

Veiculo veiculos[MAX_VEICULOS];
Entrega entregas[MAX_ENTREGAS];
Funcionario funcionarios[MAX_FUNCIONARIOS];
Cliente clientes[MAX_CLIENTES];

int numVeiculos = 0, numEntregas = 0, numFuncionarios = 0, numClientes = 0;

// Funções de manipulação de dados
void adicionarVeiculo();
void visualizarVeiculos();
void editarVeiculo();
void deletarVeiculo();
void salvarVeiculos();
void carregarVeiculos();

// Funções para manipular entregas
void Id_entrega();
void Origem_entrega();
void Chegada_entrega();
void Tempo_entrega();

// Funções auxiliares para ID
void id_criar();
void id_deletar();
void id_modificar();
void id_visualizar();


void adicionarFuncionario();
void visualizarFuncionarios();
void salvarFuncionarios();
void carregarFuncionarios();

void adicionarCliente();
void visualizarClientes();
void salvarClientes();
void carregarClientes();

int menu();

// entregas

// Funções para manipular entregas
void Id_entrega();


// Funções auxiliares para ID
void id_criar();
void id_deletar();
void id_modificar();
void id_visualizar();

// Verifica se o ID já existe
int id_existe(int id) {
    FILE *arq = fopen("entregas.bin", "rb");
    if (arq == NULL) {
        return 0; // Arquivo não existe, logo ID não existe
    }

    entrega e;
    while (fread(&e, sizeof(entrega), 1, arq) == 1) {
        if (id == e.id) {
            fclose(arq);
            return 1; // ID já existe
        }
    }
    fclose(arq);
    return 0; // ID não encontrado
}

// Menu principal
int g_entregas() {
    int escolha;
    printf("[1] ID da entrega\n");
    printf("[2] Origem\n");
    printf("[3] Destino\n");
    printf("[4] Tempo estimado\n");
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: Id_entrega(); break;
  
        default: printf("Opção inválida!\n");
    }
    return 0;
}

// Menu para ID
void Id_entrega() {
    int escolha;
    printf("[1] Criar ID\n");
    printf("[2] Deletar ID\n");
    printf("[3] Modificar ID\n");
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: id_criar(); break;
        case 2: id_deletar(); break;
        case 3: id_modificar(); break;
        default: printf("Opção inválida!\n");
    }
}

// Criar ID único e armazená-lo
void id_criar() {
    entrega novo;
    FILE *arq;

    printf("Insira o ID da entrega (precisa ser único): ");
    scanf("%d", &novo.id);

    while (id_existe(novo.id)) {
        printf("Esse ID já foi usado, tente outro!\n");
        scanf("%d", &novo.id);
    }

    printf("Insira a origem da entrega: ");
    scanf("%s", novo.origem);

    printf("Insira o destino da entrega: ");
    scanf("%s", novo.chegada);

    printf("Insira o tempo estimado (em horas): ");
    scanf("%f", &novo.tempoEstimado);

    arq = fopen("entregas.bin", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fwrite(&novo, sizeof(entrega), 1, arq);
    fclose(arq);

    printf("O ID foi salvo com sucesso!\n");
}

 void id_deletar(){
    int id_procurado;
    printf("Insira o ID que queira remover.");
    scanf("%d", &id_procurado);
    FILE *arq = fopen("entregas.bin", "rb");  // Abre o arquivo original para leitura
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo original");
        return;
    }

    FILE *arq_temp = fopen("temp.bin", "wb");  // Abre um arquivo temporário para escrita
    if (arq_temp == NULL) {
        printf("Erro ao abrir o arquivo temporário");
        fclose(arq);
        return;
    }

    entrega e;
    int encontrado = 0;

   
    while (fread(&e, sizeof(entrega), 1, arq) == 1) {
        if (e.id == id_procurado) {
            // Se o ID for o procurado, nao copia para o arquivo temporário (remoção)
            printf("ID %d removido.\n", e.id);
            encontrado = 1;
        } else {
          
            fwrite(&e, sizeof(entrega), 1, arq_temp);
        }
    }

    if (!encontrado) {
        printf("ID %d nao encontrado.\n", id_procurado);
    }

    fclose(arq);
    fclose(arq_temp);

    if (remove("entregas.bin") != 0) {
        printf("Erro ao remover o arquivo original");
        return;
    }

    if (rename("temp.bin", "entregas.bin") != 0) {
        printf("Erro ao renomear o arquivo temporário");
        return;
    }

}
void id_modificar(){
    int id;
    entrega e;
    FILE *arq = fopen("entregas.bin", "r+b");  // Abre o arquivo em modo de leitura e escrita binária

    // Verificação de abertura do arquivo
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

   
    printf("Insira o ID que queira editar: ");
    scanf("%d", &id);

   
    int encontrado = 0;

   
    while (fread(&e, sizeof(entrega), 1, arq) == 1) {
        if (id == e.id) {
            encontrado = 1;

            printf("id encontrado: \n");
            printf(" ID: %d\n", e.id);
            
            printf("Insira o novo ID (precisa ser unico): ");
            scanf("%d", &e.id);
            printf("origem: %s \n destino: %s \n ", e.origem, e.chegada);
            // Verificar se o novo ID já existe
            while (id_existe(e.id)) {
                printf("Esse ID ja foi usado, tente outro!\n");
                scanf("%d", &e.id);
            }

            printf("Insira o novo local de origem e chegada: ");
            fgets(e.origem, sizeof(e.origem), stdin);
            fgets(e.chegada, sizeof(e.chegada), stdin);
            printf("Aqui estão os novos dados inseridos. esta tudo certo? 1 para sim, 2 para nao.\n");
            printf(" ID: %d\n",e.id);
            printf("origem: %s \n destino: %s \n ", e.origem, e.chegada);

        
            int num;
            scanf("%d", &num);

            if (num == 1) {
                fseek(arq, -(long)sizeof(entrega), SEEK_CUR);
                fwrite(&e, sizeof(entrega), 1, arq);
                printf("O foi atualizado com sucesso!\n");
            } else {
                printf("A operação de atualização foi cancelada.\n");
            }
        }
    }

    if (!encontrado) {
        printf(" ID %d nao encontrado.\n", id);
        }
    

    fclose(arq);
}
void entrega_visualizar(){
    int id;
    int encontrado = 0;
    entrega e;
    FILE *arq = fopen("entregas.bin", "rb");
    if (arq == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
    }

    printf("Insira o ID a ser pesquisado:");
    scanf("%d", &id);
    while (fread(&e, sizeof(entrega), 1, arq) == 1) {
        if(id == e.id){
            encontrado = 1;
            printf("origem: %s \n chegada: %s \n ID: %d\n tempo estimado: %f",e.origem,  e.chegada, e.id, e.tempoEstimado);
            break;
        }
    }
    if(encontrado == 0){
        printf("entrega com ID nao encontrado, listando todos\n");
        fseek(arq, 0, SEEK_SET);
        while(fread(&e, sizeof(entrega), 1, arq) == 1) {
            printf("ID: %d\n", e.id);
            printf("origem: %s \n chegada: %s \n tempo estimado: %.2f", e.origem,  e.chegada, e.tempoEstimado);
        }
    }
    fclose(arq);
