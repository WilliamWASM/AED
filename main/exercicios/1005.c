#include <stdio.h>
#include <stdlib.h>

int main(){
    
    double A=100.0,B=100.0, media=0.0;

    while(A>10.0 || A<0.0){
        scanf("%lf",&A);
    }
    A*=3.5;
    while(B>10.0 || A<0.0){
        scanf("%lf",&B);
    }
    B*=7.5;
    media = (A+B)/11.0;

    printf("MEDIA = %.5f", media);
    
    return 0;
}
