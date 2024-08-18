#include <stdio.h>

int main() {
    int n, soma = 0;

    // Lê o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Declara o array com o tamanho fornecido
    int array[n];

    // Lê os elementos do array e soma diretamente
    printf("Digite %d números inteiros:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        soma += array[i];  // Soma cada elemento imediatamente após a leitura
    }

    // Imprime o resultado
    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}


