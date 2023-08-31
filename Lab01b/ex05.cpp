#include <iostream>

using namespace std;

#define LINHA 10
#define COLUNA 10

void imprime_matriz(int** m, int lin, int col){
    for (int i = 0; i < lin; i++){
        for (int y = 0; y < col; y++){
            cout << m[i][y] << " ";
        }
        cout << "\n";
    }
}

void multip_lin(int** m, int lin, int col, int valor, int alvo){
    if (alvo >= lin || alvo < 0) cout << "valor alvo fora da matriz\n";
    else {
        for (int i = 0; i < col; i++) m[alvo][i] *= valor;
    }
}

void multip_col(int** m, int lin, int col, int valor, int alvo){
    if (alvo >= col || alvo < 0) cout << "valor alvo fora da matriz\n";
    else {
        for (int i = 0; i < lin; i++) m[i][alvo] *= valor;
    }
}

int main(){
    
    int** matriz = new int*[LINHA];
    for (int i = 0; i < LINHA; i++) matriz[i] = new int[COLUNA];
    
    for (int i = 0; i < LINHA; i++){
        for (int y = 0; y < COLUNA; y++){
            matriz[i][y] = 1;
        }
    }
    
    multip_lin(matriz, LINHA, COLUNA, 5, 5); // multiplica por 5 a linha 5
    multip_col(matriz, LINHA, COLUNA, 5, 5); // multiplica por 5 a coluna 5
    
    imprime_matriz(matriz, LINHA, COLUNA);
    
    for (int i = 0; i < LINHA; i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
