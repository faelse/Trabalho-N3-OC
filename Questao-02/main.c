#include <stdio.h> 

#define N 4

int main() {
    int A[N], B[N], C[N];
    char binA[N + 1], binB[N + 1];
    int borrow = 0;

    printf("Digite o primeiro binario (%d bits): ", N);
    scanf("%s", binA); 
    
    printf("Digite o segundo binario (%d bits): ", N);
    scanf("%s", binB); 

    for (int i = 0; i < N; i++) {

        A[i] = binA[i] - '0'; 
        B[i] = binB[i] - '0';

    }
    for (int i = N-1; i >= 0; i--) {
        // borrow = 0 -> não precisei pegar nada imprestado 
        // borrow = 1 -> precisei pegar algo emprestado
        int sub = A[i] - B[i] - borrow;
        if ( sub >= 0){
            C[i] = sub;
            borrow = 0;
        }else{ // se sub der negativo, quer dizer que preciso emprestar.
            C[i] = sub + 2;
            borrow = 1;
        }
    }

    if(borrow == 1){
    printf("\n Erro! Subtração negativa.");
    return 0;
    }
    printf("\nResultado da subtração : ");
    for(int i = 0;i < N; i++){
        printf("%d", C[i]);
    }
    return 0;
}