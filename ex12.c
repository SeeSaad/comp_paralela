#include <stdio.h>

int main() {
	char palavra[100] = "Gustavo Salada Android";
	char entrada = 'a';

	printf("Palavra teste: %s\n", palavra);
	printf("Caracter '%c' encontrado na(s) posição(ões): ", entrada);
	for (int i = 0; i < 100; ++i)
		if (palavra[i] == entrada)
			printf("%d ", i);
	printf("[com posição inicial = 0]");
}
