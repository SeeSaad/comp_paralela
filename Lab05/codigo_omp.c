#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double f(double x);
void Trap(double a, int n, double h, double* global_result);

int main(int argc, char* argv[]){
    double a = 1.0, b = 1.85;
    int n = 100000000;
    double h = (b-a)/n;
    double global_result = ((f(a)+f(b))/2)*h;
    int thread_count;
    
    thread_count = strtol(argv[1], NULL, 10);
    
    // esses valores são adicionado pois são exceções, eles são calculados aqui para que
    // as threads calculem sempre a mesma coisa.
    
    // val_b nao e necessario pois as threads nao calculam o valor final
    
    double val_a = a+h;
    int val_n = n-2;
    
    #pragma omp parallel num_threads(thread_count)
    Trap(val_a, val_n, h, &global_result);
    
    printf("com n = %d trapezios, a estimativa\n", n);
    printf("da integral de %f ate %f = %.14e\n", a, b, global_result);
    return 0;
}

double f(double x){
    return exp(x);
}

void Trap(double a, int n, double h, double* global_result){
    double x, my_result;
    double local_a;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    
    local_n = n / thread_count;
    local_a = a + my_rank*local_n*h;
    
    // modificação feita para caso "n" não for divisível pelo numero de threads,
    // a ultima thread vai incluir a diferença.
    
    if (my_rank == thread_count-1){
        local_n += n % thread_count;
    }
    
    for (int i = 0; i <= local_n-1; i++){
        x = local_a + i*h;
        my_result += f(x);
    }
    
    my_result = my_result*h;
    
    #pragma omp critical
    *global_result += my_result;
}
