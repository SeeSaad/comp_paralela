#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid;
    char instring[30]; // string de entrada para leitura do pipeline
    int pip[2]; // sintaxe do pipeline
    long int fat2, fat; // fatorial/2 e fatorial
    
    fat = 20;
    fat2 = fat/2;
    
    pipe(pip);
    pid = fork();
    
    if (pid == 0){ //filho
        for (int i = fat-1; i > fat2; i--){
            fat *= i;
        }
        snprintf(instring, sizeof(instring), "%ld", fat);
        write(pip[1], instring, sizeof(instring));
        
    } else { //pai
        for (int i = fat2-1; i > 1; i--){
            fat2 *= i;
        }
        read(pip[0], instring, 30);
        long int lido;
        sscanf(instring, "%ld", &lido);
        fat2 *= lido;
        printf("fatorial = %ld\n", fat2);
    }

    return 0;
}
