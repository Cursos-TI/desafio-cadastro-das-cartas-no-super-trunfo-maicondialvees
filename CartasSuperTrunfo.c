#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTAS 100

typedef struct {
    char nome[50];
    int populacao;
    float pib;
    float area;
} Carta;

Carta cartas[MAX_CARTAS];
int totalCartas = 0;

void adicionar_carta() {
    if (totalCartas >= MAX_CARTAS) {
        printf("\nLimite de cartas atingido!\n");
        return;
    }
    
    printf("\nCadastro de nova carta:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]s", cartas[totalCartas].nome);
    printf("População (em milhões): ");
    scanf("%d", &cartas[totalCartas].populacao);
    printf("PIB (em trilhões de dólares): ");
    scanf("%f", &cartas[totalCartas].pib);
    printf("Área (em milhões de km²): ");
    scanf("%f", &cartas[totalCartas].area);
    
    totalCartas++;
    printf("\nCarta do país %s cadastrada com sucesso!\n", cartas[totalCartas - 1].nome);
}

void exibir_cartas() {
    if (totalCartas == 0) {
        printf("\nNenhuma carta cadastrada ainda!\n");
        return;
    }
    
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("País: %s\n", cartas[i].nome);
        printf("População: %d milhões\n", cartas[i].populacao);
        printf("PIB: %.2f trilhões\n", cartas[i].pib);
        printf("Área: %.2f milhões de km²\n", cartas[i].area);
    }
}

int main() {
    int escolha;
    
    while (1) {
        printf("\n1 - Adicionar Carta\n");
        printf("2 - Exibir Cartas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                adicionar_carta();
                break;
            case 2:
                exibir_cartas();
                break;
            case 3:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
}
