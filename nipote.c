#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    printf("pid : %d\n", getpid());
    int pid = fork();
    if(pid == 0){     
        printf("Processo figlio\n");
        printf("Figlio: PID = %d, PID padre = %d\n", getpid(), getppid());
        int nipote = fork();
        if(nipote == 0){
            printf("Processo nipote\n");
            printf("Nipote: PID = %d, PID padre = %d\n", getpid(), getppid());
            sleep(2);
            int a = 7;
            int b = 6;
            a = a + b;
            printf("Risultato nipote: %d\n", a);
            _exit(99);
        }       
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Figlio: Nipote terminato normalmente\n");
            printf("figlio: codice di uscita = %d\n", WEXITSTATUS(status));
        }
        _exit(42);
    }else{
        printf("Processo padre\n");
        printf("Padre: PID = %d, PID padre = %d\n", getpid(), pid);
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Padre: figlio terminato normalmente\n");
            printf("Padre: codice di uscita = %d\n", WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)){
            printf("Padre: figlio terminato da segnale\n");
            printf("Padre: segnale = %d\n", WTERMSIG(status));
        } else {
            printf("Padre: figlio terminato in modo imprevisto, status = 0x%x\n", status);
        }
    }
    return 0;
}