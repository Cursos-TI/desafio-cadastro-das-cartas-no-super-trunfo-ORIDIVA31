#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura da cidade
typedef struct {
    char estado[30];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Função para mostrar uma cidade
void mostrarCidade(Cidade c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
}

int main() {
    srand(time(NULL));

    // Lista de cidades (você pode adicionar mais!)
    Cidade cidades[] = {
        {"RJ", 1001, "Rio de Janeiro", 6748000, 1182.3, 400.5, 15},
        {"SP", 1002, "São Paulo", 12330000, 1521.0, 700.7, 10},
        {"BA", 1003, "Salvador", 2886000, 692.8, 300.0, 12},
        {"CE", 1004, "Fortaleza", 2687000, 313.8, 280.9, 9},
        {"MG", 1005, "Belo Horizonte", 2537000, 331.4, 320.2, 8},
        {"RS", 1006, "Porto Alegre", 1485000, 496.8, 250.3, 7}
    };

    int total = sizeof(cidades) / sizeof(Cidade);

    // Sorteia duas cidades diferentes
    int idxJogador = rand() % total;
    int idxOponente;
    do {
        idxOponente = rand() % total;
    } while (idxOponente == idxJogador);

    Cidade jogador = cidades[idxJogador];
    Cidade oponente = cidades[idxOponente];

    // Mostra a carta do jogador
    printf("==== Sua Carta ====\n");
    mostrarCidade(jogador);

    // Escolha de atributo
    int escolha;
    printf("\nEscolha um atributo para competir:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    float valorJogador = 0, valorOponente = 0;
    char nomeAtributo[30];

    switch (escolha) {
        case 1:
            valorJogador = jogador.populacao;
            valorOponente = oponente.populacao;
            strcpy(nomeAtributo, "População");
            break;
        case 2:
            valorJogador = jogador.area;
            valorOponente = oponente.area;
            strcpy(nomeAtributo, "Área");
            break;
        case 3:
            valorJogador = jogador.pib;
            valorOponente = oponente.pib;
            strcpy(nomeAtributo, "PIB");
            break;
        case 4:
            valorJogador = jogador.pontos_turisticos;
            valorOponente = oponente.pontos_turisticos;
            strcpy(nomeAtributo, "Pontos Turísticos");
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    // Mostra a carta do oponente
    printf("\n==== Carta do Oponente ====\n");
    mostrarCidade(oponente);

    // Resultado
    printf("\n==== Resultado ====\n");
    printf("Seu %s: %.2f\n", nomeAtributo, valorJogador);
    printf("Oponente %s: %.2f\n", nomeAtributo, valorOponente);

    if (valorJogador > valorOponente)
        printf("🎉 Você venceu!\n");
    else if (valorJogador < valorOponente)
        printf("😞 Você perdeu!\n");
    else
        printf("⚖️ Empate!\n");

    return 0;
}
