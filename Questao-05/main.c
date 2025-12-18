#include <stdio.h>

#define N 4

int main() {
    int A[N], B[N], C[2*N] = {0};
    char binA[N+1], binB[N+1];
    
    printf("Digite o primeiro binario (%d bits): ", N);
    scanf("%s", binA);
    printf("Digite o segundo binario (%d bits): ", N);
    scanf("%s", binB);
    
    for(int i = 0; i < N; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }
    
    for(int i = 0; i < N; i++) {
        if(B[N-1-i] == 1) {  
            int carry = 0;
            

            for(int j = 0; j < N; j++) {
                int pos = (2*N-1) - i - j; 
                int soma = C[pos] + A[N-1-j] + carry;
                C[pos] = soma % 2;
                carry = soma / 2;
            }
            

            for(int k = (2*N-1)-i-N; k >= 0 && carry > 0; k--) {
                int soma = C[k] + carry;
                C[k] = soma % 2;
                carry = soma / 2;
            }
        }
    }
    
    int negativo = (A[0] != B[0]);
    
    if(negativo) {
        for(int i = 0; i < 2*N; i++) {
            C[i] = (C[i] == 0) ? 1 : 0;
        }
        
        int carry = 1;
        for(int i = 2*N-1; i >= 0; i--) {
            int soma = C[i] + carry;
            C[i] = soma % 2;
            carry = soma / 2;
        }
    }
    
    printf("\nProduto (%d bits): ", 2*N);
    for(int i = 0; i < 2*N; i++) {
        printf("%d", C[i]);
    }
    printf("\n");
    
    return 0;
}