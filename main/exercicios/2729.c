#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_TAM_ITEM 21

int comparaStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int removeDuplicados(char *itens[], int n) {
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(itens[j], itens[i]) != 0) {
            j++;
            itens[j] = itens[i];
        }
    }
    return j + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char linha[10000];
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';
        char *itens[MAX_ITENS];
        int numItens = 0;
        char *token = strtok(linha, " ");
        while (token != NULL) {
            itens[numItens] = token;
            numItens++;
            token = strtok(NULL, " ");
        }
        qsort(itens, numItens, sizeof(char *), comparaStrings);
        numItens = removeDuplicados(itens, numItens);
        for (int j = 0; j < numItens; j++) {
            printf("%s", itens[j]);
            if (j < numItens - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
