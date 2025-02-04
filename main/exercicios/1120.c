#include <stdio.h>
#include <string.h>

int main() {
    char D, N[101];
    
    while (1) {
        scanf(" %c %s", &D, N);
        
        if (D == '0' && N[0] == '0') {
            break;
        }
        
        char result[101];
        int j = 0;
        
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != D) {
                result[j++] = N[i];
            }
        }
        
        result[j] = '\0';
        
        if (j == 0 || (result[0] == '0' && result[1] == '\0')) {
            printf("0\n");
        } else {
            printf("%s\n", result);
        }
    }

    return 0;
}
