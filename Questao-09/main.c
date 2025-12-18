#include <stdio.h>
#include <string.h>

#define N 2 

int hexParaBin(char hex, int bin[]) {
    int valor;
    
    if(hex >= '0' && hex <= '9') valor = hex - '0';
    else if(hex >= 'A' && hex <= 'F') valor = hex - 'A' + 10;
    else if(hex >= 'a' && hex <= 'f') valor = hex - 'a' + 10;
    else return 0;
    
    for(int i = 3; i >= 0; i--) {
        bin[i] = valor % 2;
        valor /= 2;
    }
    return 1;
}

char binParaHex(int bin[]) {
    int valor = 0;
    for(int i = 0; i < 4; i++) {
        valor = valor * 2 + bin[i];
    }
    
    if(valor < 10) return '0' + valor;
    else return 'A' + (valor - 10);
}

int main() {
    char hexA[N+1], hexB[N+1];
    int A[4*N], B[4*N], C[4*N];
    
    printf("Digite o primeiro hexadecimal (%d digitos): ", N);
    scanf("%s", hexA);
    printf("Digite o segundo hexadecimal (%d digitos): ", N);
    scanf("%s", hexB);
    
    for(int i = 0; i < N; i++) {
        int binTemp[4];
        
        if(!hexParaBin(hexA[i], binTemp)) {
            printf("Caractere hexadecimal invalido!\n");
            return 1;
        }
        for(int j = 0; j < 4; j++) A[i*4 + j] = binTemp[j];
        
        if(!hexParaBin(hexB[i], binTemp)) {
            printf("Caractere hexadecimal invalido!\n");
            return 1;
        }
        for(int j = 0; j < 4; j++) B[i*4 + j] = binTemp[j];
    }
    
    int carry = 0;
    for(int i = 4*N-1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry;
        C[i] = soma % 2;
        carry = soma / 2;
    }
    
    int overflow = 0;
    if(A[0] == B[0] && C[0] != A[0]) {
        overflow = 1;
    }
    
    if(overflow) {
        printf("\nERRO: Overflow detectado!\n");
    } else {
        printf("\nResultado em hexadecimal: ");
        for(int i = 0; i < N; i++) {
            int digitoBin[4];
            for(int j = 0; j < 4; j++) {
                digitoBin[j] = C[i*4 + j];
            }
            printf("%c", binParaHex(digitoBin));
        }
        printf("\n");
    }
    
    return 0;
}