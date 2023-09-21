#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  // Memória compartilhada
  int shmid;
  key_t key = ftok("shmfile", 65);
  shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
  int *shared_var = (int *)shmat(shmid, NULL, 0);

  *shared_var = 1;

  pid_t pid = fork();

  if (pid == 0) { // filho
    printf("Processo FILHO: Valor (antes da adicao) = %d\n", *shared_var);
    *shared_var += 2;
    printf("Processo FILHO: Valor (depois da adicao) = %d\n", *shared_var);
  }
  else { // pai
    printf("Processo PAI: Valor (antes do wait) = %d\n", *shared_var);
    wait(NULL);
    *shared_var *= 4;
    printf("Processo PAI: Valor (depois da multiplicacao) = %d\n", *shared_var);
  }
}
