#include <stdio.h>

int main() {
	char Str[100] = "Paralela";
	int entrada = 3;

	for (int i = 0; i < 100; ++i)
		if (i != entrada)
			printf("%c", Str[i]);
}
