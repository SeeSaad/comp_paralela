#include <stdio.h>

int main() {
        char Str[100] = "Paralela";
        int entrada_pos = 3;
	char entrada_char = 'g';

        for (int i = 0; i < 100; ++i) {
                if (i == entrada_pos)
                        printf("%c", entrada_char);
		printf("%c", Str[i]);
	}
}
