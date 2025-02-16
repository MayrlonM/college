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
} entrega;

typedef struct {
    int id;
    char nome[100];
} funcionarios;

typedef struct {
    int id;
    char nome[100];
    char endereco[200];
    char tipoServico[20]; // "economico", "padrao", "premium"
} Cliente;

Veiculo veiculos[MAX_VEICULOS];
entregas entregas[MAX_ENTREGAS];
funcionarios funcionarios[MAX_FUNCIONARIOS];
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
void entrega_visualizar();

// Funções auxiliares para ID
void id_criar_entregas();
void  id_deletar_entregas();
void id_modificar_entregas();


// Funções para manipular funcionarios
void Id_funcionarios();
void funcionarios_visualizar();

// Funções auxiliares para ID
void id_criar_funcionarios();
void id_deletar_funcionarios();
void id_modificar_funcionarios();
void id_visualizar_funcionarios();


void adicionarCliente();
void visualizarClientes();
void salvarClientes();
void carregarClientes();

int menu();

// entregas



// Verifica se o ID já existe
int id_existe_entregas(int id) {
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
    printf("[1] entregas\n");
    printf("[2] visualizar entregas\n");
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: Id_entrega(); break;
        case 2: entrega_visualizar(); break;
        default: printf("Opção inválida!\n");
    }
    return 0;
}

// Menu para ID
void Id_entrega() {
    int escolha;
    printf("[1] Criar \n");
    printf("[2] Deletar \n");
    printf("[3] Modificar \n");
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: id_criar_entregas(); break;
        case 2:  id_deletar_entregas(); break;
        case 3: id_modificar_entregas(); break;
        default: printf("Opção inválida!\n");
    }
}

// Criar ID único e armazená-lo
void id_criar_entregas() {
    entrega novo;
    FILE *arq;

    printf("Insira o ID da entrega (precisa ser único): ");
    scanf("%d", &novo.id);

    while (id_existe_entregas(novo.id)) {
        printf("Esse ID já foi usado, tente outro!\n");
        scanf("%d", &novo.id);
    }

    printf("Insira a origem da entrega: ");
    getchar(); 
    fgets(novo.origem, sizeof(novo.origem), stdin);

    printf("Insira o destino da entrega: ");
    
    fgets(novo.destino, sizeof(novo.destino), stdin);

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

 void id_deletar_entregas(){
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
void id_modificar_entregas(){
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
            
            int id_antigo = e.id;
do {
    printf("Insira o novo ID (precisa ser único): ");
    scanf("%d", &e.id);
} while (e.id != id_antigo && id_existe_entregas(e.id));
            printf("origem: %s \n destino: %s \n ", e.origem, e.destino);
            // Verificar se o novo ID já existe
            while (id_existe_entregas(e.id)) {
                printf("Esse ID ja foi usado, tente outro!\n");
                scanf("%d", &e.id);
            }

            printf("Insira o novo local de origem e chegada: ");
            getchar();
            fgets(e.origem, sizeof(e.origem), stdin);
            fgets(e.destino, sizeof(e.destino), stdin);
            printf("Aqui estão os novos dados inseridos. esta tudo certo? 1 para sim, 2 para nao.\n");
            printf(" ID: %d\n",e.id);
            printf("origem: %s \n destino: %s \n ", e.origem, e.destino);

        
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
            printf("origem: %s \n chegada: %s \n ID: %d\n tempo estimado: %.2f\n",e.origem,  e.destino, e.id, e.tempoEstimado);
            break;
        }
    }
    if(encontrado == 0){
        printf("entrega com ID nao encontrado, listando todos\n");
        fseek(arq, 0, SEEK_SET);
        while(fread(&e, sizeof(entrega), 1, arq) == 1) {
            printf("ID: %d\n", e.id);
            printf("origem: %s \n chegada: %s \n tempo estimado: %.2f", e.origem,  e.destino, e.tempoEstimado);
        }
    }
    fclose(arq);
}
// funcionarios



// Verifica se o ID já existe
int id_existe_funcionarios(int id) {
    FILE *arq = fopen("funcionarios.bin", "rb");
    if (arq == NULL) {
        return 0; // Arquivo não existe, logo ID não existe
    }

    funcionarios e;
    while (fread(&e, sizeof(funcionarios), 1, arq) == 1) {
        if (id == e.id) {
            fclose(arq);
            return 1; // ID já existe
        }
    }
    fclose(arq);
    return 0; // ID não encontrado
}

// Menu principal
int g_funcionarios() {
    int escolha;
    printf("[1] funcionario\n");
    printf("[2] visualizar funcionario\n");
   
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: Id_funcionarios(); break;
        case 2:  funcionarios_visualizar(); break;
        default: printf("Opção inválida!\n");
    }
    return 0;
}

// Menu para ID
void Id_funcionarios() {
    int escolha;
    printf("[1] Criar ID\n");
    printf("[2] Deletar ID\n");
    printf("[3] Modificar ID\n");
    scanf("%d", &escolha);    

    switch (escolha) {
        case 1: id_criar_funcionarios(); break;
        case 2: id_deleta_funcionarios(); break;
        case 3: id_modificar_funcionarios(); break;
        default: printf("Opção inválida!\n");
    }
}

// Criar ID único e armazená-lo
void id_criar_funcionarios() {
    funcionarios novo;
    FILE *arq;

    printf("Insira o ID do funcionarios (precisa ser único): ");
    scanf("%d", &novo.id);

    while (id_existe_funcionarios(novo.id)) {
        printf("Esse ID já foi usado, tente outro!\n");
        scanf("%d", &novo.id);
    }

    printf("Insira o nome do funcionario: ");
    scanf("%s", novo.nome);


    arq = fopen("funcionarios.bin", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fwrite(&novo, sizeof(funcionarios), 1, arq);
    fclose(arq);

    printf("O ID foi salvo com sucesso!\n");
}

 void id_deletar_funcionarios(){
    int id_procurado;
    printf("Insira o ID que queira remover.");
    scanf("%d", &id_procurado);
    FILE *arq = fopen("funcionarios.bin", "rb");  // Abre o arquivo original para leitura
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

    funcionarios e;
    int encontrado = 0;

   
    while (fread(&e, sizeof(funcionarios), 1, arq) == 1) {
        if (e.id == id_procurado) {
            // Se o ID for o procurado, nao copia para o arquivo temporário (remoção)
            printf("ID %d removido.\n", e.id);
            encontrado = 1;
        } else {
          
            fwrite(&e, sizeof(funcionarios), 1, arq_temp);
        }
    }

    if (!encontrado) {
        printf("ID %d nao encontrado.\n", id_procurado);
    }

    fclose(arq);
    fclose(arq_temp);

    if (remove("funcionarios.bin") != 0) {
        printf("Erro ao remover o arquivo original");
        return;
    }

    if (rename("temp.bin", "funcionarios.bin") != 0) {
        printf("Erro ao renomear o arquivo temporário");
        return;
    }

}
void id_modificar_funcionarios(){
    int id;
    funcionarios e;
    FILE *arq = fopen("funcionarios.bin", "r+b");  // Abre o arquivo em modo de leitura e escrita binária

    // Verificação de abertura do arquivo
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

   
    printf("Insira o ID que queira editar: ");
    scanf("%d", &id);

   
    int encontrado = 0;

   
    while (fread(&e, sizeof(funcionarios), 1, arq) == 1) {
        if (id == e.id) {
            encontrado = 1;

            printf("id encontrado: \n");
            printf(" ID: %d\n", e.id);
            
            printf("Insira o novo ID (precisa ser unico): ");
            scanf("%d", &e.id);
           printf("Digite o novo nome: ");
            getchar(); // Limpa buffer do Enter anterior
            fgets(e.nome, sizeof(e.nome), stdin);
            int id_antigo = e.id;
do {
    printf("Insira o novo ID (precisa ser único): ");
    scanf("%d", &e.id);
} while (e.id != id_antigo && id_existe_funcionarios(e.id));

           
            printf("Aqui estão os novos dados inseridos. esta tudo certo? 1 para sim, 2 para nao.\n");
            printf(" ID: %d\n",e.id);
            printf("novo nome: %s \n", e.nome);

        
            int num;
            scanf("%d", &num);

            if (num == 1) {
                fseek(arq, -(long)sizeof(funcionarios), SEEK_CUR);
                fwrite(&e, sizeof(funcionarios), 1, arq);
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
void funcionarios_visualizar(){
    int id;
    int encontrado = 0;
    funcionarios e;
    FILE *arq = fopen("funcionarios.bin", "rb");
    if (arq == NULL) {
    printf("Erro ao abrir o arquivo");
    return;
    }

    printf("Insira o ID a ser pesquisado:");
    scanf("%d", &id);
    while (fread(&e, sizeof(funcionarios), 1, arq) == 1) {
        if(id == e.id){
            encontrado = 1;
            printf("nome: %s \n ID: %d\n ",e.nome,  e.id);
            break;
        }
    }
    if(encontrado == 0){
        printf("funcionario com ID nao encontrado, listando todos\n");
        fseek(arq, 0, SEEK_SET);
        while(fread(&e, sizeof(funcionario), 1, arq) == 1) {
            printf("ID: %d\n", e.id);
            printf("nome: %s \n", e.nome);
        }
    }
    fclose(arq);
}
