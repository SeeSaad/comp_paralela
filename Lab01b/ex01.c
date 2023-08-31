#include <stdio.h>

int main()
{
    int i, j, menor, linha;
    int Matriz[3][3] = {{2,3,5},{7,11,13},{17,19,23}};
    menor = Matriz[0][0];
    linha = 0;
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            if (menor > Matriz[i][j]){
                menor = Matriz[i][j];
                linha = i;
            }
        }
    }
    printf("Linha que contém o menor valor: linha %d\n",linha);
    return 0;
}
