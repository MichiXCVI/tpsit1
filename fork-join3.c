#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int prog1(){
    int a = 5;
    int b = 3;
    a = a * b;
    printf("Risultato 1: %d\n", a);
    return a;
}

int prog2(){
    int a = 9;
    int b = 4;       
    a = a * b;
    printf("Risultato 2: %d\n", a);
    return a;
}

int prog3(){
    int a = 4;
    int b = 7;       
    a = a * b;
    printf("Risultato 3: %d\n", a);
    return a;
}

int main(){
    int pid = fork();
    if(pid == 0){     
        int proc3 = fork();
        if(proc3 == 0){
            exit(prog1());
        }       
        int ris_1;
        wait(&ris_1);
            int a;
            a = prog2() + WEXITSTATUS(ris_1);
        exit(a);
    }else{
        int ris_2;
        wait(&ris_2);
            int a;
            a = prog3() + WEXITSTATUS(ris_2);    
            printf("Risultato finale: %d\n", a);    
    }
    return 0;
}

