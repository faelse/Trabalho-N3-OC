#include <stdio.h>

#define N 1  
#define BITS (4*N)  

int main() {
    int A[BITS], B[BITS], C[BITS];
    char binA[BITS+1], binB[BITS+1];
    
    printf("Digite o primeiro BCD (%d bits): ", BITS);
    scanf("%s", binA);
    printf("Digite o segundo BCD (%d bits): ", BITS);
    scanf("%s", binB);
    
    for(int i = 0; i < BITS; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }
    
    int borrow = 0;
    
    for(int i = BITS-1; i >= 0; i--) {
        int sub = A[i] - B[i] - borrow;
        
        if(sub >= 0) {
            C[i] = sub;
            borrow = 0;
        } else {
            C[i] = sub + 10;  
            borrow = 1;
        }
    }
    
    if(borrow == 1) {
        printf("\nERRO: Subtracao negativa!\n");
        return 0;
    }
    
    for(int i = 0; i < N; i++) {
        int inicio = i * 4;
        int valor = 0;
        
        for(int j = 0; j < 4; j++) {
            valor = valor * 2 + C[inicio + j];
        }
        
        if(valor > 9) {
            valor -= 6;
            
            for(int j = 3; j >= 0; j--) {
                C[inicio + j] = valor % 2;
                valor /= 2;
            }
        }
    }
    
    printf("\nResultado: ");
    for(int i = 0; i < BITS; i++) {
        printf("%d", C[i]);
    }
    printf("\n");
    
    return 0;
}