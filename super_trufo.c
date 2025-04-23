#include <stdio.h>
#include <string.h>

#define NUM_ATTR 5
#define NUM_CARTAS 5

// Estrutura de uma carta
typedef struct {
    char nome[30];
    int populacao;        // Em milhões
    int area;             // Em mil km²
    float pib;            // Em trilhões de USD
    float idh;            // 0 a 1
    int expectativaVida;  // Em anos
} Carta;

// Função para mostrar atributos da carta
void mostrarCarta(Carta c) {
    printf("\n📄 País: %s\n", c.nome);
    printf("1. População: %d milhões\n", c.populacao);
    printf("2. Área: %d mil km²\n", c.area);
    printf("3. PIB: %.2f trilhões USD\n", c.pib);
    printf("4. IDH: %.3f\n", c.idh);
    printf("5. Expectativa de Vida: %d anos\n", c.expectativaVida);
}

// Função para comparar atributos
int comparar(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return c1.populacao - c2.populacao;
        case 2: return c1.area - c2.area;
        case 3: return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? -1 : 0;
        case 4: return (c1.idh > c2.idh) ? 1 : (c1.idh < c2.idh) ? -1 : 0;
        case 5: return c1.expectativaVida - c2.expectativaVida;
        default: return 0;
    }
}

int main() {
    // Criação de cartas
    Carta cartas[NUM_CARTAS] = {
        {"Brasil", 213, 8516, 1.9, 0.765, 76},
        {"Japão", 125, 378, 4.9, 0.925, 84},
        {"Canadá", 38, 9984, 2.2, 0.936, 82},
        {"Noruega", 5, 385, 0.5, 0.961, 83},
        {"Índia", 1408, 3287, 3.7, 0.633, 70}
    };

    // Sorteio de carta para jogador e computador
    Carta jogador = cartas[0];    // Brasil
    Carta computador = cartas[1]; // Japão

    printf("=== Sua Carta ===\n");
    mostrarCarta(jogador);

    int escolha;
    printf("\nEscolha um atributo para competir (1 a 5): ");
    scanf("%d", &escolha);

    printf("\n=== Carta do Computador ===\n");
    mostrarCarta(computador);

    int resultado = comparar(jogador, computador, escolha);

    printf("\nResultado: ");
    if (resultado > 0) {
        printf("Você venceu! 🎉\n");
    } else if (resultado < 0) {
        printf("Computador venceu! 🤖\n");
    } else {
        printf("Empate! 😐\n");
    }

    return 0;
}
