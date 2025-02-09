#include <stdio.h>

int verifica_linha(int m[9][9]){
    for (int i=0;i<9;i++){
        int count[10]={0};
        for(int j=0;j<9;j++){
            int numero=m[i][j];
            if(numero <1 || numero > 9 || count[numero]>0 ){
                return 0;
            }
            count[numero]++;
        }
    }
    return 1;
}

int verifica_coluna(int m[9][9]){
    for (int j=0;j<9;j++){
        int count[10]={0};
        for(int i=0;i<9;i++){
            int numero=m[i][j];
            if(numero <1 || numero > 9 || count[numero]>0 ){
                return 0;
            }
            count[numero]++;
        }
    }
    return 1;
}

int verifica_quadrado(int m[9][9]){
    for(int linha=0; linha<9;linha+=3){
        for(int coluna=0;coluna<9;coluna+=3){
            int count[10]={0};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int numero=m[linha+i][coluna+j];
                    if(numero<1 || numero > 9 || count[numero]>0){
                        return 0;
                    }
                    count[numero]++;
                }
            }
        }
    }
    return 1;
}

int verifica_sudoku_completo(int m[9][9]){
    return verifica_coluna(m) && verifica_linha(m) && verifica_quadrado(m);
}

int main(){
    int n; // numero de matrizes
    
    scanf("%d", &n);

    for(int k=1; k <= n; k++){
        int matriz[9][9];
        for(int i=0; i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        if(verifica_sudoku_completo(matriz)){
            printf ("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
