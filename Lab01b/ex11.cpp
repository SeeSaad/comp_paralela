#include <iostream>
#include <vector>

void SomaLinhas(std::vector<std::vector<int>>& matriz, size_t linha1, int linha2) {
    for (size_t j = 0; j < matriz[linha1].size(); ++j) {
        matriz[linha2][j] += matriz[linha1][j];
    }
}
void MultiplicaLinhas(std::vector<std::vector<int>>& matriz, size_t linha1, int linha2) {
    for (size_t j = 0; j < matriz.size(); ++j) {
        matriz[linha2][j] *= matriz[linha1][j];
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

    SomaLinhas(matriz, 0, 1);
    MultiplicaLinhas(matriz, 0, 1);

    std::cout << "\nMatriz após somar e multiplicar linhas 1 e 2 da matriz, e armazenar na linha 2, respectivamente:" << std::endl;
    printMatriz(matriz);
    return 0;
}
