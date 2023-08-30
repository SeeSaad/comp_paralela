#include <iostream>
#include <string>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
    int peso;
    float altura;
};

int main(){
    
    Pessoa pessoas[3];
    
    pessoas[0].nome = "Gustavo";
    pessoas[1].nome = "Bruno";
    pessoas[2].nome = "Tomas";

    pessoas[0].idade = 20;
    pessoas[1].idade = 5;
    pessoas[2].idade = 7;
    
    pessoas[0].peso = 95;
    pessoas[1].peso = 40;
    pessoas[2].peso = 120;
    
    pessoas[0].altura = 1.85;
    pessoas[1].altura = 1.50;
    pessoas[2].altura = 1.51;
    
    for (int i = 0; i < 3; ++i) {
        cout << "Nome: " << pessoas[i].nome << ", Idade: " << pessoas[i].idade << ", Peso: " << pessoas[i].peso << ", Altura: " << pessoas[i].altura << "\n";
    }
    
    return 0;
}
