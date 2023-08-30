#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int num) {
    if (num == 9) {
        return 0;
    } else {
        return num + 1;
    }
}

int main()
{
    char numeroOriginal[6] = "820187", numeroAtual;
    char *ptrNumeroOriginal = numeroOriginal;
    int qntDias = 16;

    printf("o numero final para o dia 174 é: %s\n\n", numeroOriginal);
    printf("endereco de memoria do numero original: %p\n\n", ptrNumeroOriginal);
    for (int i = 1; i <= qntDias; i++)
    {
        int n0,n1,n2,n3,n4,n5;
        n0 = ptrNumeroOriginal[0] - '0';
        n1 = ptrNumeroOriginal[1] - '0';
        n2 = ptrNumeroOriginal[2] - '0';
        n3 = ptrNumeroOriginal[3] - '0';
        n4 = ptrNumeroOriginal[4] - '0';
        n5 = ptrNumeroOriginal[5] - '0';
        n1 = soma(n1);
        n5 = soma(n5);
        if (n1 == 8) {
            n0 = soma(n0);
            n4 = soma(n4);
        }
        ptrNumeroOriginal[0] = n0 + '0';
        ptrNumeroOriginal[1] = n1 + '0';
        ptrNumeroOriginal[2] = n2 + '0';
        ptrNumeroOriginal[3] = n3 + '0';
        ptrNumeroOriginal[4] = n4 + '0';
        ptrNumeroOriginal[5] = n5 + '0';
        printf("dia %d, numero: %d%d%d%d%d%d\n",i,n0,n1,n2,n3,n4,n5);

    }

    printf("o numero final para o dia 174 é: %s\n\n", numeroOriginal);
    return 0;
}
