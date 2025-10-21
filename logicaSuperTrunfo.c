#include <stdio.h>

int main() {

    // ---------------------------------------------------------
    // CADASTRO DAS CARTAS (funcionalidade comum)
    // ---------------------------------------------------------
    char nome1[50], nome2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    printf("===== CADASTRO DAS CARTAS =====\n\n");

    printf("Carta 1 - Nome da Cidade: ");
    scanf(" %[^\n]", nome1);
    printf("Populacao: ");
    scanf("%d", &populacao1);
    printf("Area (km2): ");
    scanf("%f", &area1);
    printf("PIB (bilhoes): ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos1);

    printf("\nCarta 2 - Nome da Cidade: ");
    scanf(" %[^\n]", nome2);
    printf("Populacao: ");
    scanf("%d", &populacao2);
    printf("Area (km2): ");
    scanf("%f", &area2);
    printf("PIB (bilhoes): ");
    scanf("%f", &pib2);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Cálculo de densidade demográfica
    float dens1 = populacao1 / area1;
    float dens2 = populacao2 / area2;

    // ---------------------------------------------------------
    // MENU DE ATRIBUTOS (dinâmico e interativo)
    // ---------------------------------------------------------
    printf("\n===== MENU DE ATRIBUTOS =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");

    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    // Verificação simples de validade
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opcao invalida! Encerrando o programa.\n");
        return 0;
    }

    // Segundo menu dinâmico (remove o atributo já escolhido)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue;
        switch (i) {
            case 1: printf("1 - Populacao\n"); break;
            case 2: printf("2 - Area\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turisticos\n"); break;
            case 5: printf("5 - Densidade Demografica\n"); break;
        }
    }

    printf("Escolha: ");
    scanf("%d", &atributo2);

    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
        printf("Opcao invalida ou repetida! Encerrando o programa.\n");
        return 0;
    }

    // ---------------------------------------------------------
    // SELEÇÃO DE VALORES DOS ATRIBUTOS ESCOLHIDOS
    // ---------------------------------------------------------
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    // Primeiro atributo
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos1; valor1_c2 = pontos2; break;
        case 5: valor1_c1 = dens1; valor1_c2 = dens2; break;
        default: printf("Erro interno.\n"); return 0;
    }

    // Segundo atributo
    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos1; valor2_c2 = pontos2; break;
        case 5: valor2_c1 = dens1; valor2_c2 = dens2; break;
        default: printf("Erro interno.\n"); return 0;
    }

    // ---------------------------------------------------------
    // COMPARAÇÃO AVANÇADA COM LÓGICA TERNÁRIA E ANINHADA
    // ---------------------------------------------------------
    printf("\n===== COMPARACAO =====\n");

    // Comparação do primeiro atributo
    int resultado1 = (atributo1 == 5)
        ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0))
        : (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));

    // Comparação do segundo atributo
    int resultado2 = (atributo2 == 5)
        ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0))
        : (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));

    // Soma total dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // Determina o vencedor (lógica aninhada)
    int vencedor = (soma1 > soma2) ? 1 : ((soma2 > soma1) ? 2 : 0);

    // ---------------------------------------------------------
    // EXIBIÇÃO DOS RESULTADOS
    // ---------------------------------------------------------
    printf("\nResultados:\n");
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", nome1, valor1_c1, valor2_c1, soma1);
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", nome2, valor1_c2, valor2_c2, soma2);

    printf("\n===== RESULTADO FINAL =====\n");
    switch (vencedor) {
        case 1:
            printf("Vencedora: %s\n", nome1);
            break;
        case 2:
            printf("Vencedora: %s\n", nome2);
            break;
        default:
            printf("Empate!\n");
            break;
    }

    printf("\n============================================\n");
    printf("Comparacao concluida com sucesso!\n");

    return 0;
}
