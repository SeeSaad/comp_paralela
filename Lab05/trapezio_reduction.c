#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double f(double x) { return exp(x); }

int main(int argc, char* argv[]) {
    double global_result = 0.0;
    double a = 1, b = 1.85, h, approx;
    int n = 100;
    int thread_count;

    thread_count = strtol(argv[1], NULL, 10);

    h = (b - a) / n;
    approx = (f(a) + f(b)) / 2.0;
    #pragma omp parallel for num_threads(thread_count) reduction(+: approx)
    for (int i = 1; i <= n - 1; i++)
        approx += f(a + i * h);
    approx = h * approx;

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, approx);
    return 0;
}
