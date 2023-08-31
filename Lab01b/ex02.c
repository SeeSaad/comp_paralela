#include <stdio.h>

int main(){ 
    float N1 = 8, N2 = 7, N3 = 8, ME = 9;

    float ma = (N1 + (2*N2) + (3*N3) + ME) / 7;

    printf("MA = %.2f\n", ma);
    if (ma >= 9) printf("maior ou igual a 9, conceito A\n");
    else if (ma >= 7.5) printf("maior ou igual a 7.5, conceito B\n");
    else if (ma >= 6) printf("maior ou igual a 6, conceito C\n");
    else if (ma >= 4) printf("maior ou igual a 4, conceito D\n");
    else printf("menor que 4, conceito E\n");
}
