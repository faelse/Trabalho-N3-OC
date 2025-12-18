#include <stdio.h>
#include <string.h>

#define N 4  // A - B = A + (-B)

void complemento2(int vetor[], int resultado[]) {
    int carry = 1;
    
    for (int i = 0; i < N; i++) {
        resultado[i] = (vetor[i] == 0) ? 1 : 0;
    }
    
    for (int i = N - 1; i >= 0; i--) {
        int soma = resultado[i] + carry;
        resultado[i] = soma % 2;
        carry = soma / 2;
    }
}

int main() {
    int A[N], B[N], C[N], B_neg[N];
    char binA[N + 1], binB[N + 1];
    
    printf("Digite o primeiro binario (%d bits, complemento de 2): ", N);
    scanf("%s", binA);
    printf("Digite o segundo binario (%d bits, complemento de 2): ", N);
    scanf("%s", binB);
    
    for (int i = 0; i < N; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }
    
    complemento2(B, B_neg);
    
    int carry = 0;
    for (int i = N - 1; i >= 0; i--) {
        int soma = A[i] + B_neg[i] + carry;
        C[i] = soma % 2;
        carry = soma / 2;
    }
    
    int overflow = 0;
    if (A[0] == B_neg[0] && C[0] != A[0]) {
        overflow = 1;
    }
}
    