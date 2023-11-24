#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <gmp.h>

#define TRABALHO_THREAD 9 // trabalho por iteração da thread
#define PRECISION 1000000

// as iterações para o calculo de e contém dependencias, caso não fizesse com dependencias,
// cada thread teria que calcular sozinha n! (com "n" tendendo ao infinito).
// isso teria um custo cada vez mais exponencial para cada iteração.

// apesar de não ser o recomendado, decidimos criar threads explicitas (número explicito),
// cada thread irá fazer uma parte do trabalho e irá depender da outra na hora de obter
// o seu resultado e somar na variável global
// (controlado por mutex)

// cada thread terá o trabalho de calcular o fatorial em um certo limite, por exemplo,
// de 10! - 18!. A dependência dessa thread seria o cálculo de 9!,
// o trabalho local dessa thread seria calcular 
// (10! - 9!, 11! - 9!, ... , 18! - 9!) 
// (10, 10* 11, 10 * 11 * 12 , ...)
// e guardar tais valores,
// no final, a thread irá esperar o calculo de 9! (variável global) e calcular todos os fatoriais, e soma-los na resposta.

// para sincronização das threads foi pensado que, para que uma thread escreva em uma variável global, tal variável precisa estar com valor "-1",
// se isso impactar a performance, usar uma outra lista de variáveis auxiliares.
// ou seja, quando uma thread ler uma variável global e não precisar mais dela, setar para -1 o auxiliar ou a própria variável.

// valores vetor global = [9!, 18!, 27!] (o que cada thread vai calcular)
// vetor leitura global = ['w',  'w',   'r']
// 1o - primeira thread = [1, 2!, 3!, 4!, ... , 9!] (vet trabalho local)
// 2o - primeira thread = for n in vet_trabalho_local, vet_global[n-1 % total_de_threads] * n

// #pragma omp parallel num_threads(var)

// omp_init_lock(&)
// omp_set_lock(&)
// omp_unset_lock(&)

// [1 2 3 4 5 6 7 8 9] threads
// [  |              ] dados
// [w r w w w w w w w] ver pode ler



void thread_func(int max_n, mpf_t* euler, mpf_t data_vet[], char data_read[], omp_lock_t locks_vet[]){
    //criar vetor local
    //fazer leitura de last_index
    // calcular o maior fatorial e escrever, depois fazer outros calculos

    int thread_index = omp_get_thread_num();
    int max_threads = omp_get_num_threads();

    mpf_t vet_local[TRABALHO_THREAD];
    mpf_t dependencia_fat; //fatorial

    for (int i = 0; i < TRABALHO_THREAD; i++){
        mpf_init(vet_local[i]);
        mpf_set_prec(vet_local[i], PRECISION);
    }
    mpf_init(dependencia_fat);
    mpf_set_prec(dependencia_fat, PRECISION);

    int last_index = (thread_index + max_threads - 1) % max_threads; // index de leitura

    int pulo_iteracao = TRABALHO_THREAD*(max_threads); // 

    int sprint_end;
    int sprint_start;
    int i; // iterador do vetor local

    for (int iteracao = 0; iteracao < max_n; iteracao += pulo_iteracao){
        // printf("%d %d\n", iteracao / pulo_iteracao, thread_index);
        sprint_end = iteracao+(thread_index+1)*TRABALHO_THREAD;
        sprint_start = iteracao+thread_index*TRABALHO_THREAD+1;
        i = 0; // iterador do vetor local

        // printf("thread= %d start= %d end= %d\n", thread_index, sprint_start, sprint_end);

        for (int y = 0; y < TRABALHO_THREAD; y++) mpf_set_d(vet_local[y], 1); // limpa e prepara vetor local

        for (int sprint = sprint_start; sprint < sprint_end; sprint++){ // 2 10 - 17
            mpf_mul_ui(vet_local[i], vet_local[i], sprint);
            mpf_mul(vet_local[i+1], vet_local[i+1], vet_local[i]);
            i += 1;
        }
        mpf_mul_ui(vet_local[i], vet_local[i], sprint_end);

        // nesse ponto, o vetor local foi calculado

        while(data_read[last_index] != 'r');
        omp_set_lock(&locks_vet[last_index]);
        mpf_set(dependencia_fat ,data_vet[last_index]);
        omp_unset_lock(&locks_vet[last_index]);
        data_read[last_index] = 'w';

        mpf_mul(vet_local[TRABALHO_THREAD-1], vet_local[TRABALHO_THREAD-1], dependencia_fat); //18!

        while(data_read[thread_index] != 'w');
        omp_set_lock(&locks_vet[thread_index]);
        mpf_set(data_vet[thread_index], vet_local[TRABALHO_THREAD-1]);
        omp_unset_lock(&locks_vet[thread_index]);
        data_read[thread_index] = 'r';

        for (int y = 0; y < TRABALHO_THREAD-1; y++){
            mpf_mul(vet_local[y], vet_local[y], dependencia_fat); // multiplica a dependencia
            mpf_ui_div(vet_local[y], 1, vet_local[y]); // 1/n!
            # pragma omp critical
                mpf_add(*euler, *euler, vet_local[y]);
        }
        mpf_ui_div(vet_local[TRABALHO_THREAD-1], 1, vet_local[TRABALHO_THREAD-1]);
        #pragma omp critical
            mpf_add(*euler, *euler, vet_local[TRABALHO_THREAD-1]);
    }

    for (int i = 0; i < TRABALHO_THREAD; i++) {
        mpf_clear(vet_local[i]);
    }
    mpf_clear(dependencia_fat);
}

int main() {
    int max_n = 100000;
    int thread_count;

    # pragma omp parallel
        # pragma omp master
            thread_count = omp_get_max_threads(); // adquire maximo de threads

    omp_lock_t locks_vet[thread_count]; // vetor de mutexes
    char data_read[thread_count]; // vetor de variaveis que indicam se a posição no vetor "data_vet" estão ou não preparados para ler
    mpf_t data_vet[thread_count]; // vetor de troca de dados entre as threads
    mpf_t soma_euler; // variavel de soma do numero de euler (controlada por #pragma omp critical)

    for (int i = 0; i < thread_count; i++){
        mpf_init(data_vet[i]);
        mpf_set_prec(data_vet[i], PRECISION);
        data_read[i] = 'w';
        omp_init_lock(&locks_vet[i]);
    }

    mpf_init(soma_euler);
    mpf_set_d(soma_euler, 1);
    mpf_set_prec(soma_euler, PRECISION);
    mpf_set_d(data_vet[thread_count-1], 1); // valor 1 para a variavel global (inicialização)
    data_read[thread_count-1] = 'r'; // preparando o vetor para inicialização (indica que a primeira thread pode trabalhar)

    # pragma omp parallel num_threads(thread_count)
    thread_func(max_n, &soma_euler, data_vet, data_read, locks_vet);

    FILE* file = fopen("output.txt", "w");

    mpf_out_str(file, 10, 0, soma_euler);
    fclose(file);

    for (int i = 0; i < thread_count; i++) {
        mpf_clear(data_vet[i]);
        omp_destroy_lock(&locks_vet[i]);
    }
    mpf_clear(soma_euler);
    
    return 0;
}
