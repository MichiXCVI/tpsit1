#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        int a = 5;
        int b = 3;       
        a = a * b;
        printf("Figlio: risultato = %d\n", a);
        _exit(a);
    }else{
        int a = 9;
        int b = 4; 
        a = a * b;
        int result_figlio;
        wait(&result_figlio);
        int result = WEXITSTATUS(result_figlio) + a;
        printf("Padre: risultato = %d\n", a);
        printf("Risultato = %d\n", result);
        return 0;
    }
}