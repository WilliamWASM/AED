#include <stdio.h>
#include <string.h>

#define MAX_AMIGOS 1000
#define MAX_NOME 100

int main() {
    char amigos_atuais[MAX_AMIGOS][MAX_NOME], novos_amigos[MAX_AMIGOS][MAX_NOME];
    char amigo_indicado[MAX_NOME];
    int n_amigos_atuais = 0, n_novos_amigos = 0;
    int i, pos_indicado = -1;

    char linha[1000];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(amigos_atuais[n_amigos_atuais], token);
        n_amigos_atuais++;
        token = strtok(NULL, " \n");
    }

    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(novos_amigos[n_novos_amigos], token);
        n_novos_amigos++;
        token = strtok(NULL, " \n");
    }

    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0';  // Remove a nova linha

    if (strcmp(amigo_indicado, "nao") != 0) {
        for (i = 0; i < n_amigos_atuais; i++) {
            if (strcmp(amigos_atuais[i], amigo_indicado) == 0) {
                pos_indicado = i;
                break;
            }
        }
    }

    if (pos_indicado != -1) {
    
        for (i = n_amigos_atuais - 1; i >= pos_indicado; i--) {
            strcpy(amigos_atuais[i + n_novos_amigos], amigos_atuais[i]);
        }

        
        for (i = 0; i < n_novos_amigos; i++) {
            strcpy(amigos_atuais[pos_indicado + i], novos_amigos[i]);
        }

        
        n_amigos_atuais += n_novos_amigos;
    } else {
      for (i = 0; i < n_novos_amigos; i++) {
            strcpy(amigos_atuais[n_amigos_atuais], novos_amigos[i]);
            n_amigos_atuais++;
        }
    }
    for (i = 0; i < n_amigos_atuais; i++) {
        printf("%s", amigos_atuais[i]);
        if (i < n_amigos_atuais - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
