#include <stdio.h>

#define N 4  // número de bits

int main() {
    int A[N], B[N], Q[N] = {0}, R[N] = {0};
    char binA[N+1], binB[N+1];
    
    printf("Digite o dividendo (%d bits): ", N);
    scanf("%s", binA);
    printf("Digite o divisor (%d bits): ", N);
    scanf("%s", binB);
    
    for(int i = 0; i < N; i++) {
        A[i] = binA[i] - '0';
        B[i] = binB[i] - '0';
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-1; j++) {
            R[j] = R[j+1];
        }
        R[N-1] = A[i]; 
        
        int podeSubtrair = 1;
        
        for(int j = 0; j < N; j++) {
            if(R[j] > B[j]) {
                podeSubtrair = 1;
                break;
            }
            if(R[j] < B[j]) {
                podeSubtrair = 0;
                break;
            }
        }
        
        if(podeSubtrair) {
            int borrow = 0;
            for(int j = N-1; j >= 0; j--) {
                int sub = R[j] - B[j] - borrow;
                if(sub < 0) {
                    R[j] = sub + 2;
                    borrow = 1;
                } else {
                    R[j] = sub;
                    borrow = 0;
                }
            }
            Q[i] = 1;  
        } else {
            Q[i] = 0;  
        }
    }
    
    printf("\nQuociente: ");
    for(int i = 0; i < N; i++) printf("%d", Q[i]);
    
    printf("\nResto: ");
    for(int i = 0; i < N; i++) printf("%d", R[i]);
    printf("\n");
    
    return 0;
}