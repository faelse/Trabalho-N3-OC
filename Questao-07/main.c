#include <stdio.h>

#define N 1  
#define BITS (4*N)  

int main() {
    int A[BITS], B[BITS], C[BITS+4] = {0};  
    char binA[BITS+1], binB[BITS+1];
    
    printf("Digite o primeiro BCD (%d bits = %d digitos): ", BITS, N);
    scanf("%s", binA);
    printf("Digite o segundo BCD (%d bits = %d digitos): ", BITS, N);
    scanf("%s", binB);
    
    for(int i = 0; i < BITS; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }
    
    int carry = 0;
    
    for(int digito = N-1; digito >= 0; digito--) {
        int pos_inicio = digito * 4;
        
        for(int i = 3; i >= 0; i--) {
            int pos = pos_inicio + i;
            int soma = A[pos] + B[pos] + carry;
            C[pos+4] = soma % 2;  
            carry = soma / 2;
        }
        
        int valor_digito = 0;
        for(int i = 0; i < 4; i++) {
            valor_digito = valor_digito * 2 + C[pos_inicio + 4 + i];
        }
        
        if(valor_digito > 9 || carry == 1) {
            int ajuste[4] = {0, 1, 1, 0};  
            int carry_ajuste = 0;
            
            for(int i = 3; i >= 0; i--) {
                int pos = pos_inicio + 4 + i;
                int soma = C[pos] + ajuste[i] + carry_ajuste;
                C[pos] = soma % 2;
                carry_ajuste = soma / 2;
            }
            
            carry = carry_ajuste;  
        } else {
            carry = 0;  
        }
    }
    
    if(carry == 1) {
        C[3] = 1;  
    }
    
    // Exibir
    printf("\nResultado da soma BCD (%d bits): ", BITS+4);
    for(int i = 0; i < BITS+4; i++) {
        printf("%d", C[i]);
        if((i+1) % 4 == 0 && i != BITS+3) printf(" ");  
    }
    printf("\n");
    
    return 0;
}