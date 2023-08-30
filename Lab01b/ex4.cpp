#include <iostream>
#include <string>

using namespace std;

int comp_cpp(string n1, string n2){
    int s_n1 = n1.size();
    int s_n2 = n2.size();
    int menor;
    
    if (s_n1 <= s_n2) menor = s_n1;
    else menor = s_n2;
    
    for (int i = 0; i < menor; i++){
        if (int(n1[i]) < int(n2[i])) return 1;
        else if (int(n1[i]) > int(n2[i])) return -1;
    }
    
    if (s_n1 == s_n2) return 0;
    else if (s_n1 < s_n2) return 1;
    else return -1;
}

int main(){ 
    string nome1 = "Tomasssssss";
    string nome2 = "Tomasssss";
    int comparacao = comp_cpp(nome1, nome2);
    
    if (comparacao == 1)
        cout << "Em ordem alfabética: " << nome1 << ", " << nome2 << "\n";
    else if (comparacao == 0)
        cout << "Os nomes são iguais: " << nome1 << "\n";
    else
        cout << "Em ordem alfabética: " << nome2 << ", " << nome1 << "\n";

    return 0;
}
