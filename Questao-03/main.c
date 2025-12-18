#include <stdio.h>
#include <string.h>

#define N 4  

int main() {
    int A[N], B[N], C[N];
    char binA[N + 1], binB[N + 1];
    int carry = 0;

    printf("Digite o primeiro binario (%d bits, complemento de 2): ", N);
    scanf("%s", binA);
    printf("Digite o segundo binario (%d bits, complemento de 2): ", N);
    scanf("%s", binB);

    for (int i = 0; i < N; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }

    for (int i = N - 1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry;
        C[i] = soma % 2;
        carry = soma / 2;
    }

    int overflow = 0;
    if (A[0] == B[0] && C[0] != A[0]) {
        //Não podem ter o msm sinal e o resultado n pode ter sinal diferente
        overflow = 1;
    }

    if (overflow) {
        printf("\nErro: Overflow detectado! A soma nao e representavel em %d bits.\n", N);
    } else {
        printf("\nResultado da soma (complemento de 2): ");
        for (int i = 0; i < N; i++) {
            printf("%d", C[i]);
        }
        printf("\n");
    }

    return 0;
}