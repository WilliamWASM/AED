#include <stdio.h>
#include <string.h>

#define MAX_PALAVRAS 50
#define MAX_COMPRIMENTO 50

int main() {
    int N, i, max_len;
    char palavras[MAX_PALAVRAS][MAX_COMPRIMENTO + 1];
    int primeiro_teste = 1;
    
    while (scanf("%d", &N) && N != 0) {
        if (!primeiro_teste) {
            printf("\n");
        }
        primeiro_teste = 0;
        
        max_len = 0;
        for (i = 0; i < N; i++) {
            scanf("%s", palavras[i]);
            int len = strlen(palavras[i]);
            if (len > max_len) {
                max_len = len;
            }
        }
        
        for (i = 0; i < N; i++) {
            printf("%*s\n", max_len, palavras[i]);
        }
    }
    
    return 0;
}
