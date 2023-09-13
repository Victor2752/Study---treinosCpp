#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// char numeroOriginal[6] = "820187";
char numeroOriginal[6] = "770172";
// Definindo a data alvo (09/03/2023)
struct tm target_date = {
    tm_year : 2023 - 1900,
    tm_mon : 2,
    tm_mday : 9
};
char *ptrNumeroOriginal = numeroOriginal;

int soma(int num)
{
    if (num == 9)
    {
        return 0;
    }
    else
    {
        return num + 1;
    }
}

int soma2(int num)
{
    if (num == 9)
    {
        return 1;
    }
    else
    {
        return num + 2;
    }
}

int *map2int()
{
    int *num = malloc(6 * sizeof(int));
    for (int j = 0; j < 6; j++)
    {
        num[j] = ptrNumeroOriginal[j] - '0';
    }
    return num;
}

void map2char(int *num)
{
    for (int j = 0; j < 6; j++)
    {
        ptrNumeroOriginal[j] = num[j] + '0';
    }
}

int calculaDias()
{
    // Obtendo a data atual do sistema
    time_t current_time;
    time(&current_time);
    struct tm *current_date = localtime(&current_time);

    // Calculando a diferença em segundos
    double diff_seconds = difftime(current_time, mktime(&target_date));

    // Convertendo a diferença de segundos para dias
    int diff_days = (int)(diff_seconds / (60 * 60 * 24));

    // Calculando a diferença em anos
    int diff_years = current_date->tm_year - target_date.tm_year;

    // Calculando a diferença em meses
    int diff_months = diff_years * 12 + (current_date->tm_mon - target_date.tm_mon);

    // Calculando o dia do mês
    int day_month = current_date->tm_mday;

    if (diff_months > 0)
    {
        int *num = map2int();
        num[0] = 7;
        num[1] = 9;
        for (int i = 0; i < diff_months; i++)
        {
            num[3] = soma2(num[3]);
        }
        num[4] = 7;
        num[5] = 4;
        map2char(num);
    }

    // printf("Diferença em dias entre 14/08/2023 e a data atual: %d dias\n", diff_days);
    // printf("Diferença em meses entre 14/08/2023 e a data atual: %d meses\n", diff_months);
    return day_month;
}

void calcula_numero(int diff_days)
{
    int *num = map2int();
    printf("%02d/%02d - %s\n", 1, 1, numeroOriginal);
    for (int i = 2; i <= diff_days; i++)
    {
        num[5] = soma(num[5]);
        num[1] = soma(num[1]);
        if (num[1] == 8)
        {
            num[0] = soma(num[0]);
            num[4] = soma(num[4]);
        }
        map2char(num);
        printf("%02d/%02d - %s\n", i, i, numeroOriginal);
    }
}

int main()
{
    // Obtendo a data atual do sistema
    time_t current_time;
    time(&current_time);
    struct tm *current_date = localtime(&current_time);

    // Calculando a diferença em anos
    int diff_years = current_date->tm_year - target_date.tm_year;
    // Calculando a diferença em meses
    int diff_months = diff_years * 12 + (current_date->tm_mon - target_date.tm_mon);

    if (diff_months > 0)
    {
        int *num = map2int();
        num[0] = 7;
        num[1] = 9;
        for (int i = 0; i < diff_months; i++)
        {
            num[3] = soma2(num[3]);
        }
        num[4] = 7;
        num[5] = 4;
        map2char(num);
    }

    calcula_numero(current_date->tm_mday);

    printf("o numero final para o dia %d é: %s\n\n", current_date->tm_mday, numeroOriginal);
    return 0;
}
