
#include "funcao.c"




void adicionarVeiculo() {
    Veiculo veiculo;
    printf("Digite o ID do veículo: ");
    scanf("%d", &veiculo.id);
    printf("Digite o tipo do veículo (caminhão, van, moto, etc.): ");
    scanf("%s", veiculo.tipo);
    printf("Digite a capacidade de carga (em kg): ");
    scanf("%f", &veiculo.capacidadeCarga);
    printf("Digite o status do veículo (livre/ocupado): ");
    scanf("%s", veiculo.status);
    
    veiculos[numVeiculos++] = veiculo;
    printf("Veículo adicionado com sucesso!\n");
}

void visualizarVeiculos() {
    printf("\n--- Veículos ---\n");
    for (int i = 0; i < numVeiculos; i++) {
        printf("ID: %d, Tipo: %s, Capacidade: %.2f kg, Status: %s\n", 
                veiculos[i].id, veiculos[i].tipo, veiculos[i].capacidadeCarga, veiculos[i].status);
    }
}

void editarVeiculo() {
    int id;
    printf("Digite o ID do veículo que deseja editar: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == id) {
            printf("Digite o novo tipo de veículo: ");
            scanf("%s", veiculos[i].tipo);
            printf("Digite a nova capacidade de carga: ");
            scanf("%f", &veiculos[i].capacidadeCarga);
            printf("Digite o novo status do veículo (livre/ocupado): ");
            scanf("%s", veiculos[i].status);
            printf("Veículo atualizado com sucesso!\n");
            return;
        }
    }
    printf("Veículo não encontrado.\n");
}

void deletarVeiculo() {
    int id;
    printf("Digite o ID do veículo que deseja deletar: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == id) {
            for (int j = i; j < numVeiculos - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }
            numVeiculos--;
            printf("Veículo deletado com sucesso!\n");
            return;
        }
    }
    printf("Veículo não encontrado.\n");
}

void salvarVeiculos() {
    FILE *file = fopen("veiculos.dat", "wb");
    if (file == NULL) {
        printf("Erro ao salvar os dados!\n");
        return;
    }
    fwrite(&numVeiculos, sizeof(int), 1, file);
    fwrite(veiculos, sizeof(Veiculo), numVeiculos, file);
    fclose(file);
}

void carregarVeiculos() {
    FILE *file = fopen("veiculos.dat", "rb");
    if (file == NULL) return;
    
    fread(&numVeiculos, sizeof(int), 1, file);
    fread(veiculos, sizeof(Veiculo), numVeiculos, file);
    fclose(file);
}

void menu() {
    int opcao;
    while (1) {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar Veículo\n");
        printf("2. Visualizar Veículos\n");
        printf("3. Editar Veículo\n");
        printf("4. Deletar Veículo\n");
        printf("5. Gerar Relatório de Entregas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: adicionarVeiculo(); break;
            case 2: visualizarVeiculos(); break;
            case 3: editarVeiculo(); break;
            case 4: deletarVeiculo(); break;
            case 5: gerarRelatorioEntregas(); break;
            case 6: salvarVeiculos(); exit(0); break;
            default: printf("Opção inválida!\n"); break;
        }
    }
}

void gerarRelatorioEntregas() {
    printf("\n--- Relatório de Entregas ---\n");
    for (int i = 0; i < numEntregas; i++) {
        printf("Entrega ID: %d, Funcionário ID: %d, Veículo ID: %d, Cliente ID: %d\n", 
               entregas[i].id, entregas[i].id, entregas[i].id, entregas[i].id);
    }
}

int main() {
    carregarVeiculos();
    carregarEntregas();
    carregarFuncionarios();
    carregarClientes();
    
    menu();
    
    return 0;
}