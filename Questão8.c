#include <stdio.h>
#include <math.h>

int main() {
    
    // Declarando Variaveis
    int A, B, C;

    while (1) {
        // Leitura dos valores de A, B e C
        scanf("%d %d %d", &A, &B, &C);

        // Verifica se todos os valores são 0 para encerrar o programa
        if (A == 0 && B == 0 && C == 0) {
            break;
        }

        // Calcula a área construída
        double area_construida = (A * B * 100.0) / C;

        // Calcula o lado do terreno quadrado
        int lado = (int) sqrt(area_construida);

        // Imprime o lado
        printf("%d\n", lado);
    }

    return 0;
}
