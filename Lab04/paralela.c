#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 10
#define L_MATRIZ 10
#define C_MATRIZ 10000

int matriz[L_MATRIZ][C_MATRIZ];
int vet_inicial[C_MATRIZ];
long vet_final[L_MATRIZ];
long l_threads[N_THREADS];

void aloca_matriz();
void imprime_matriz();
void imprime_vet();

void *calc_matriz(void* arg);

int main(){
    
    aloca_matriz(); // popula com dados
    
    pthread_t thread_handles[N_THREADS];
    for (long num = 0; num < N_THREADS; num++) l_threads[num] = num;
    
    for (int thread = 0; thread < N_THREADS; thread++){
        pthread_create(&thread_handles[thread], NULL, calc_matriz, (void*)l_threads[thread]);
    }
    
    for (int thread = 0; thread < N_THREADS; thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    
    imprime_vet();
    printf("\n\n");
    
    return 0;
}

void *calc_matriz(void* arg){
    long linha = (long) arg;
    
    for (int i = 0; i < C_MATRIZ; i++){
        vet_final[linha] += matriz[linha][i] * vet_inicial[i];
    }
    
    return NULL;
}

void imprime_vet(){
    for (int i = 0; i < L_MATRIZ; i++){
        printf("%ld  ", vet_final[i]);
    }
    printf("\n");
}

void aloca_matriz(){
    for (int i = 0; i < L_MATRIZ; i++){
        for (int y = 0; y < C_MATRIZ; y++){
            matriz[i][y] = y+i;
            if (i == 0) vet_inicial[y] = y;
        }
    }
}
