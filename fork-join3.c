#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){     
        int proc3 = fork();
        if(proc3 == 0){
            int a = 5;
            int b = 3;
            a = a * b;
            printf("Risultato 1: %d\n", a);
            _exit(a);
        }       
        int ris_1;
        wait(&ris_1);
            int a = 9;
            int b = 4;
            a = a * b;
            printf("Risultato 2: %d\n", a);
            a = a + WEXITSTATUS(ris_1);
        _exit(a);
    }else{
        int ris_2;
        wait(&ris_2);
            int a = 7;
            int b = 4;
            a = a * b;
            printf("Risultato 2: %d\n", a);
            a = a + WEXITSTATUS(ris_2);    
            printf("Risultato finale: %d\n", a);    
    }
    return 0;
}