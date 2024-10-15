#include <stdio.h>
 
int main() {
 
    int idade_dias,meses,dias,dias_sobrando;
    
    scanf("%d", &idade_dias);
    
    dias = idade_dias%365;
    meses = dias/30;
    dias_sobrando = dias%30;
    
    printf("%d ano(s)\n",idade_dias/365);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias_sobrando);
 
    return 0;
}
