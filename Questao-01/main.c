#include <stdio.h>
#include <string.h>

#define N 4   

int main() {
    int A[N], B[N], C[N + 1];
    char binA[N + 1], binB[N + 1];
    int carry = 0;

    printf("Digite o primeiro binario (%d bits): ", N);
    scanf("%s", binA); 
    
    printf("Digite o segundo binario (%d bits): ", N);
    scanf("%s", binB); 

    for (int i = 0; i < N; i++) {

        /*
            ASCII 0 = 48
            ASCII 1 = 49
            como funciona a conversão?
            se binA[i] = 0 -> '0' - '0' que é o mesmo que (ASCII) 48, então fazemos (ASCII) 48 - (ASCII) 48 -> que dá 0.
            se binA[i] = 1 -> '1' - '0' que é o mesmo que (ASCII) 49, então fazemos (ASCII) 49 - (ASCII) 48 -> que dá 1.
        */

        A[i] = binA[i] - '0'; 
        B[i] = binB[i] - '0';

    }

    for (int i = N - 1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry; 
        C[i + 1] = soma % 2; 
        carry = soma / 2; 
    }

    C[0] = carry;

    printf("\nResultado da soma: ");
    for (int i = 0; i < N + 1; i++) {
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}
