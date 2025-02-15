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
