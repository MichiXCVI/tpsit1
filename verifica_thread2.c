#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int proc(){     
    return 10 - 3;
}

int proc1(){    
    return 59 + 74;
}

int proc3(){     
    return 44 + 77;
}

int main(){
    pid_t pid = fork();
    if(pid == 0){
        exit(proc());
    }

    pid_t pid1 = fork();
    if(pid1 == 0){
        exit(proc());
    }

    int a = proc3();

    int ris_1;
    wait(&ris_1);
    int ris_2;
    wait(&ris_2);
    
    a = a * WEXITSTATUS(ris_1) * WEXITSTATUS(ris_2);
    printf("Risultato finale: %d\n", a);   
    return 0;
}