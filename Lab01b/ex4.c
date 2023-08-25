#include <stdio.h>
#include <string.h>

int main()
{
    	char nome1[] = "Tomás";
    	char nome2[] = "Gustavo";
    	int comparacao;

   	 comparacao = strcmp(nome1, nome2);

	if (comparacao == 1)
        	printf("Em ordem alfabética: %s, %s\n", nome1, nome2);
	else if (comparacao == 0)
		printf("Os nomes são iguais: %s", nome1);
	else
		printf("Em ordem alfabética: %s, %s\n", nome2, nome1);

	return 0;
}
