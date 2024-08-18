#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototipando a função de substituição
string substitute(string text, string key);

// Função principal
int main(int argc, string argv[])
{
    // Verifica se há exatamente 2 argumentos (o nome do programa e a chave)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Verifica se a chave tem exatamente 26 caracteres
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Verifica se a chave contém apenas caracteres alfabéticos e se são únicos
    bool used[26] = {false};  // Array para rastrear caracteres já usados
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        
        int index = tolower(key[i]) - 'a';
        if (used[index])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        used[index] = true;
    }

    // Obtém o texto a ser criptografado do usuário
    string plaintext = get_string("plaintext: ");

    // Chama a função de substituição e imprime o texto criptografado
    string ciphertext = substitute(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Função que realiza a substituição de acordo com a chave fornecida
string substitute(string text, string key)
{
    // Itera sobre cada caractere do texto
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = toupper(key[text[i] - 'A']);
            }
            else
            {
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }
    return text;
}
