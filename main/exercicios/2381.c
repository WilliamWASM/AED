#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char nomes[N][21];
    for (int i = 0; i < N; i++) scanf("%s", nomes[i]);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char temp[21];
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp);
            }
        }
    }
    printf("%s\n", nomes[K - 1]);
    return 0;
}
