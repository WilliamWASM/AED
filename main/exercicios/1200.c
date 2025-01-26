#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->valor) {
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

int buscar(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return 1;
    } else if (valor < raiz->valor) {
        return buscar(raiz->esquerdo, valor);
    } else {
        return buscar(raiz->direito, valor);
    }
}

void percursoInfixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        percursoInfixo(raiz->esquerdo, primeiro);
        if (!*primeiro) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        percursoInfixo(raiz->direito, primeiro);
    }
}

void percursoPrefixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (!*primeiro) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        percursoPrefixo(raiz->esquerdo, primeiro);
        percursoPrefixo(raiz->direito, primeiro);
    }
}

void percursoPosfixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        percursoPosfixo(raiz->esquerdo, primeiro);
        percursoPosfixo(raiz->direito, primeiro);
        if (!*primeiro) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
}

int main() {
    No* raiz = NULL;
    char comando[10];
    char valor;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            percursoInfixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            percursoPrefixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            percursoPosfixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (buscar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        }
    }

    return 0;
}
