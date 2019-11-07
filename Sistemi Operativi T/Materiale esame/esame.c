#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define NUM_PROCESSI 2
#define MAX_STRING_LEN 50
#define TRUE 1
#define FALSE 0

void wait_child() {
	int pid_terminated, status;
	pid_terminated = wait(&status);
	if(WIFEXITED(status))
		printf("\nPADRE: terminazione volontaria del figlio %d con stato %d\n", pid_terminated, WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("\nPADRE: terminazione involontaria del figlio %d a causa del segnale %d\n", pid_terminated, WTERMSIG(status));
}

int main(int argc, char* argv[]){
	if(argc != 1){
		printf("Formato:\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * fd_pipe[0]: lettura
	 * fd_pipe[1]: scrittura
	 */
	int fd_pipe[2];
	if(pipe(fd_pipe) < 0){
		perror("Errore nella creazione della pipe:\n");
		exit(EXIT_FAILURE);
	}

	int pidx[2];
	for(int i = 0; i < NUM_PROCESSI; i++){
		pidx[i] = fork();
		if(pidx[i] < 0){
			printf("Errore nella creazione del processo P%d\n", i+1);
			exit(EXIT_FAILURE);
		}else if(pidx[i] == 0){
			printf("Sono il processo P%d con pid: %d\n", i+1, getpid());
			switch(i){
				case 0:
				//codice P1
				exit(EXIT_SUCCESS);
				break;
				case 1:
				//codice P2
				exit(EXIT_SUCCESS);
				break;
				default:
				break;
			}
		}
	}

	//codice P0
	for(int i = 0; i < NUM_PROCESSI; i++){
		wait_child();
	}
}