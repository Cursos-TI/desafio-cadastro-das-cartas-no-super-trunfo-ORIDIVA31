#include <stdio.h>

int main() {
    int Numero_de_pontos_turisticos;
    float Km;
    char nome_da_cidade[50];
    int populacao;
    float PIB;
    float Area; 

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &Numero_de_pontos_turisticos);

    printf("Digite a distância em Km: \n");
    scanf("%f", &Km);

    printf("Digite o nome da cidade: \n");
    scanf("%49s", nome_da_cidade); 

    printf("Digite a população da cidade: \n");
    scanf("%d", &populacao); 

    printf("Digite o valor do PIB: \n");
    scanf("%f", &PIB);

    printf("Digite a área da cidade em km²: \n");
    scanf("%f", &Area);

    printf("\n--- Dados da Cidade ---\n");
    printf("Cidade: %s\n", nome_da_cidade);
    printf("Pontos turísticos: %d\n", Numero_de_pontos_turisticos);
    printf("População: %d\n", populacao);
    printf("Distância: %.2f Km\n", Km);
    printf("PIB: %.2f\n", PIB);
    printf("Área: %.2f km²\n", Area);

    return 0;
}
