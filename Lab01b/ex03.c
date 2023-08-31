#include <stdio.h>

void print_sequencia(int inicio, int fim) {
    for (int i = inicio; i <= fim; i++)
        printf("%d ", i);
    printf("\n");
}

void print_espaco() {
    printf("  ");
}

int main() {
    int entrada = 9;
    for (int i = 1; i <= entrada; ++i) {
        for (int j = 1; j < i; ++j)
            print_espaco();
        print_sequencia(i, entrada);
        --entrada;
    }
}
