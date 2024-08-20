#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototipando a função de substituição
string substitute(string texto, string chave);

// Função principal
int main(int argc, string argv[])
{
    // Verifica se há exatamente 2 argumentos (o nome do programa e a chave)
    if (argc != 2)
    {
        printf("Usage: ./substituiçao chave\n");
        return 1;
    }

    string key = argv[1];

    // Verifica se a chave tem exatamente 26 caracteres
    if (strlen(chave) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }

    // Verifica se a chave contém apenas caracteres alfabéticos e se são únicos
    bool usado[26] = {false};  // Array para rastrear caracteres já usados
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(chave[i]))
        {
            printf("A chave deve conter apenas caracteres alfabéticos.\n");
            return 1;
        }
        
        int index = tolower(chave[i]) - 'a';
        if (used[index])
        {
            printf("A chave não deve conter caracteres repetidos.\n");
            return 1;
        }
        usado[index] = true;
    }

    // Obtém o texto a ser criptografado do usuário
    string plaintexto = get_string("plaintexto: ");

    // Chama a função de substituição e imprime o texto criptografado
    string ciphertexto = substitute(plaintexto, chave);
    printf("ciphertexto: %s\n", ciphertexto);

    return 0;
}

// Função que realiza a substituição de acordo com a chave fornecida
string substitute(string texto, string chave)
{
    // Itera sobre cada caractere do texto
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isalpha(texto[i]))
        {
            if (isupper(texto[i]))
            {
                text[i] = toupper(chave[texto[i] - 'A']);
            }
            else
            {
                texto[i] = tolower(chave[texto[i] - 'a']);
            }
        }
    }
    return texto;
}
