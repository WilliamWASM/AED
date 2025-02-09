#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void retiraDefeito(char *, char);
void retiraZeros(char *, char *);

void main (){

    unsigned short i, j;
    char numero[300], numeroDefeituoso;
    char numeroSemZero[300];

    while (true)
    {

        scanf(" %c %s", &numeroDefeituoso, numero);

        if (numeroDefeituoso == '0' && (strcmp(numero, "0") == 0))
            break;

        retiraDefeito(numero, numeroDefeituoso);

        retiraZeros(numero, numeroSemZero);

        if (!strlen(numeroSemZero))
            printf("0\n");
        else
            printf("%s\n", numeroSemZero);

        memset(numero, 0, sizeof(numero));
        memset(numeroSemZero, 0, sizeof(numeroSemZero));

    }

}

void retiraDefeito(char *numero, char numeroDefeituoso){

    unsigned short i;

    i = 0;
    while (numero[i])
    {

        if (numero[i] == numeroDefeituoso)
            numero[i] = 'A';
        i++;

    }

}

void retiraZeros(char *numero, char *numeroSemZero){

    unsigned short i, j;
    char aux[300] = { 0 };

    i = j = 0;
    while (numero[i])
    {

        if (numero[i] != 'A')
            aux[j++] = numero[i];

        i++;
    }

    if (j == 0)
        aux[j] = '0';

    i = j = 0;
    
    while (aux[i] == '0')
        i++;

    while (aux[i])
        numeroSemZero[j++] = aux[i++];

    numeroSemZero[j] = '\0';

}
