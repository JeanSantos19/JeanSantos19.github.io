#include <stdio.h>
#include <cs50.h>

// Função que solicita o número do cartão de crédito do usuário
long get_card_number(void)
{
    long number;
    do
    {
        // Solicita que o usuário insira um número de cartão
        number = get_long("Number: ");
    }
    // Garante que o número seja positivo
    while (number < 0);
    return number;
}

// Função que implementa o Algoritmo de Luhn para verificar a validade do cartão
bool luhn_check(long card_number)
{
    int sum = 0;
    bool alternate = false;

    // Itera sobre cada dígito do número do cartão
    while (card_number > 0)
    {
        // Extrai o último dígito
        int digit = card_number % 10;

        // Se for um dígito em posição alternada (a partir do penúltimo), dobra-o
        if (alternate)
        {
            digit *= 2;
            // Se o dígito dobrado for maior que 9, subtrai 9 para reduzir a um único dígito
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        // Soma o dígito (modificado ou não) à soma total
        sum += digit;

        // Alterna a flag para o próximo dígito
        alternate = !alternate;

        // Remove o último dígito para processar o próximo
        card_number /= 10;
    }

    // O cartão é válido se a soma total for divisível por 10
    return (sum % 10 == 0);
}

// Função que identifica o tipo de cartão (AMEX, MASTERCARD, VISA) com base nos dígitos iniciais e no comprimento
string get_card_type(long card_number)
{
    int length = 0;
    long start_digits = card_number;

    // Calcula o comprimento do número e os dois primeiros dígitos
    while (start_digits >= 100)
    {
        start_digits /= 10;
        length++;
    }
    length += 2; // Ajusta o comprimento após o loop

    // Verifica se é um cartão American Express
    if ((start_digits == 34 || start_digits == 37) && length == 15)
    {
        return "AMEX";
    }
    // Verifica se é um cartão MasterCard
    else if (start_digits >= 51 && start_digits <= 55 && length == 16)
    {
        return "MASTERCARD";
    }
    // Verifica se é um cartão Visa
    else if ((start_digits / 10 == 4) && (length == 13 || length == 16))
    {
        return "VISA";
    }
    else
    {
        // Retorna "INVALID" se não for nenhuma das opções acima
        return "INVALID";
    }
}

int main(void)
{
    // Obtém o número do cartão do usuário
    long card_number = get_card_number();

    // Verifica a validade do cartão usando o Algoritmo de Luhn
    if (luhn_check(card_number))
    {
        // Imprime o tipo de cartão se for válido
        printf("%s\n", get_card_type(card_number));
    }
    else
    {
        // Imprime "INVALID" se o número do cartão não passar na verificação de Luhn
        printf("INVALID\n");
    }
    return 0;
}
