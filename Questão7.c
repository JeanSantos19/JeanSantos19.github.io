#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Verifica se há exatamente dois argumentos (o nome do programa e a chave)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converte a chave para um número inteiro
    int key = atoi(argv[1]);

    // Verifica se a chave é um número positivo
    if (key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Solicita o texto a ser criptografado
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Itera sobre cada caractere do texto
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Verifica se o caractere é uma letra
        if (isalpha(plaintext[i]))
        {
            // Criptografa letras maiúsculas
            if (isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
            }
            // Criptografa letras minúsculas
            else if (islower(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
            }
        }
        else
        {
            // Imprime caracteres não alfabéticos sem criptografá-los
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
