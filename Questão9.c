#include <stdio.h>

int main() {
    int N;

    // Leitura do número de jogadores
    scanf("%d", &N);

    int fichas[N];
    int max_fichas = 0;
    int ultimo_a_rir = 0;

    // Leitura dos números de fichas dos jogadores
    for (int i = 0; i < N; i++) {
        scanf("%d", &fichas[i]);
        
        // Verifica se o número de fichas é maior que o máximo encontrado
        if (fichas[i] > max_fichas) {
            max_fichas = fichas[i];
            ultimo_a_rir = i + 1; // Índice 1-indexado
        }
    }

    // Imprime o índice do jogador que será o último a rir
    printf("%d\n", ultimo_a_rir);

    return 0;
}
