#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char numeroOriginal[6] = "820187";
char *ptrNumeroOriginal = numeroOriginal;
int n0,n1,n2,n3,n4,n5;

int soma(int num) {
    if (num == 9) {
        return 0;
    } else {
        return num + 1;
    }
}

int calculaDias() {
    // Definindo a data alvo (14/08/2023)
    struct tm target_date = {0};
    target_date.tm_year = 2023 - 1900; // Ano - 1900
    target_date.tm_mon = 7; // Mês (0-11, então 7 representa agosto)
    target_date.tm_mday = 14; // Dia do mês

    // Obtendo a data atual do sistema
    time_t current_time;
    time(&current_time);
    struct tm *current_date = localtime(&current_time);

    // Calculando a diferença em segundos
    double diff_seconds = difftime(current_time, mktime(&target_date));

    // Convertendo a diferença de segundos para dias
    int diff_days = (int)(diff_seconds / (60 * 60 * 24));

    printf("Diferença em dias entre 14/08/2023 e a data atual: %d dias\n", diff_days);
    return diff_days;
}

int main()
{
    int diff_days = calculaDias();
    int num[6];
    for (int i = 1; i <= diff_days; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            num[j] = ptrNumeroOriginal[j] - '0';
        }
        num[5] = soma(num[5]);
        num[1] = soma(num[1]);
        if (num[1] == 8) {
            num[0] = soma(num[0]);
            num[4] = soma(num[4]);
        }
        for (int j = 0; j < 6; j++)
        {
            ptrNumeroOriginal[j] = num[j] + '0';
        }
        printf("dia  %02d, numero: %d%d%d%d%d%d\n",i,num[0],num[1],num[2],num[3],num[4],num[5]);
    }

    printf("o numero final para o dia %d é: %s\n\n", diff_days, numeroOriginal);
    return 0;
}
