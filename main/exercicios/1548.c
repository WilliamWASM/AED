#include <stdio.h>

int main() {
    int N, M;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);
        int notas[M], copia[M], nao_trocaram = 0;

        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            copia[i] = notas[i];
        }

        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (copia[i] < copia[j]) {
                    int temp = copia[i];
                    copia[i] = copia[j];
                    copia[j] = temp;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (notas[i] == copia[i]) {
                nao_trocaram++;
            }
        }

        printf("%d\n", nao_trocaram);
    }

    return 0;
}
