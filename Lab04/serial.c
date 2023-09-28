#include <stdio.h>
#include <stdlib.h>

#define N_THREADS 10
#define L_MATRIZ 10
#define C_MATRIZ 10000

int matriz[L_MATRIZ][C_MATRIZ];
int vet_inicial[C_MATRIZ];
long vet_final[L_MATRIZ];

void aloca_matriz();
void imprime_vet();
void calc_matriz_serial();

int main() {
    
    aloca_matriz(); // popula com dados
    calc_matriz_serial();
    
    imprime_vet();
    printf("\n\n");
    
    return 0;
}

void calc_matriz_serial() {
    for (int linha = 0; linha < L_MATRIZ; linha++) {
        for (int i = 0; i < C_MATRIZ; i++) {
            vet_final[linha] += matriz[linha][i] * vet_inicial[i];
        }
    }
}

void imprime_vet() {
    for (int i = 0; i < L_MATRIZ; i++) {
        printf("%ld  ", vet_final[i]);
    }
    printf("\n");
}

void aloca_matriz() {
    for (int i = 0; i < L_MATRIZ; i++) {
        for (int y = 0; y < C_MATRIZ; y++) {
            matriz[i][y] = y + i;
            if (i == 0) vet_inicial[y] = y;
        }
    }
}
