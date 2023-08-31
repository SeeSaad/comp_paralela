#include <iostream>
#include <vector>
#include <cmath>

void substituiNegativos(std::vector<std::vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) { // size_t é um tipo inteiro da estrutura vector
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = std::abs(matriz[i][j]);
            }
        }
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
        { 1, -2, 3 },
        { -4, 5, -6 },
        { 7, -8, -9 }
    };

    std::cout << "Matriz original:" << std::endl;
    printMatriz(matriz);

    substituiNegativos(matriz);

    std::cout << "\nMatriz com valores em módulo:" << std::endl;
    printMatriz(matriz);
    return 0;
}
