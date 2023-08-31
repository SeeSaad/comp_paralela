#include <iostream>

using namespace std;

#define LINHA 6
#define COLUNA 10

void imprime_matriz(int** m, int lin, int col){
    for (int i = 0; i < lin; i++){
        for (int y = 0; y < col; y++){
            cout << m[i][y] << " ";
        }
        cout << "\n";
    }
}

void cria_transposta(int** m, int lin, int col){
    int lin_t = col;
    int col_t = lin;
    
    int** m_t = new int*[lin_t];
    for (int i = 0; i < lin_t; i++) m_t[i] = new int[col_t];
    
    for (int i = 0; i < lin_t; i++){
        for (int y = 0; y < col_t; y++){
            m_t[i][y] = m[y][i];
        }
    }
    
    cout << "\n\nTransposta:\n\n";
    imprime_matriz(m_t, lin_t, col_t);
    
    for (int i = 0; i < lin_t; i++) delete[] m_t[i];
    delete[] m_t;
}

int main(){
    cout << "este exercicio é identico ao ex 6, portanto, foi copiado\n";
    int** matriz = new int*[LINHA];
    for (int i = 0; i < LINHA; i++) matriz[i] = new int[COLUNA];
    
    int cont = 10;
    
    for (int i = 0; i < LINHA; i++){
        for (int y = 0; y < COLUNA; y++){
            matriz[i][y] = cont;
            cont += 1;
        }
    }
    
    imprime_matriz(matriz, LINHA, COLUNA);
    cria_transposta(matriz, LINHA, COLUNA);
    
    for (int i = 0; i < LINHA; i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
