#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct {
    int x, y;
} Par;

int main() {
    int colunas, linhas;
    char mapa[MAX][MAX];
    int visitados[MAX][MAX] = {0};

   
    scanf("%d %d", &colunas, &linhas);

    
    for (int i = 0; i < linhas; ++i) {
        scanf("%s", mapa[i]);
    }

    Par pos = {0, 0}; 
    int encontrouTesouro = 0; 

    while (1) {
        char atual = mapa[pos.y][pos.x];
        visitados[pos.y][pos.x] = 1; 
        if (atual == '*') {
            encontrouTesouro = 1; 
            break;
        }

        if (atual == '.') {
            break; 
        }

      
        if (atual == '<') {
            if (pos.x - 1 < 0) break;
            while (pos.x > 0 && mapa[pos.y][pos.x - 1] == '.') {
                pos.x--;
            }
            pos.x--;
        } else if (atual == '>') {
            if (pos.x + 1 >= colunas) break;
            while (pos.x < colunas - 1 && mapa[pos.y][pos.x + 1] == '.') {
                pos.x++;
            }
            pos.x++;
        } else if (atual == '^') {
            if (pos.y - 1 < 0) break;
            while (pos.y > 0 && mapa[pos.y - 1][pos.x] == '.') {
                pos.y--;
            }
            pos.y--;
        } else if (atual == 'v') {
            if (pos.y + 1 >= linhas) break;
            while (pos.y < linhas - 1 && mapa[pos.y + 1][pos.x] == '.') {
                pos.y++;
            }
            pos.y++;
        }

        if (visitados[pos.y][pos.x]) {
            break; 
        }
    }

    printf("%c\n", encontrouTesouro ? '*' : '!');
    return 0;
}
