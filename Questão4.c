#include <stdio.h>
#include <math.h>

int main(void)
{
    float valor;
    
    // Receber informações do usuario
    printf("Troco devido: ");
    scanf("%f", &valor);
    
    // Função usada para arredondar qualquer numero flutuante.
    int centavos = round(valor * 100);
    
    // Convertendo para centavos
    int moedas = 0;
    moedas += centavos / 25;  // Moedas de 25 centavos
    centavos %= 25;
    moedas += centavos / 10;  // Moedas de 10 centavos
    centavos %= 10;
    moedas += centavos / 5;   // Moedas de 5 centavos
    centavos %= 5;
    moedas += centavos;       // Moedas de 1 centavos

    printf("%d\n", moedas);
    return 0;
}
