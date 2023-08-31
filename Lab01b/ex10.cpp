#include <iostream>
#include <vector>

void multiplicaLinha(std::vector<std::vector<int>>& matriz, size_t linhaMatriz, int multiplica) {
    for (size_t j = 0; j < matriz[linhaMatriz].size(); ++j) {
        matriz[linhaMatriz][j] *= multiplica;
    }
}
void multiplicaColuna(std::vector<std::vector<int>>& matriz, size_t colunaMatriz, int multiplica) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        matriz[i][colunaMatriz] *= multiplica;
    }
}
void printMatriz(const std::vector<std::vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    std::vector<std::vector<int>> matriz = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    std::cout << "Matriz original:" << std::endl;
    printMatriz(matriz);

    size_t linhaMatriz = 1;
    int multiplica = 2;
    multiplicaLinha(matriz, linhaMatriz, multiplica);

    size_t colunaMatriz = 2;
    multiplica = 3;
    multiplicaColuna(matriz, colunaMatriz, multiplica);

    std::cout << "\nMatriz após multiplicar segunda linha por 2 e terceira coluna por 3:" << std::endl;
    printMatriz(matriz);
    return 0;
}
