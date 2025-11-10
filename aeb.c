#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("%d", getpid());
    int pid = fork();
    if(pid == 0){
        printf("Processo figlio");
        sleep(2);
        
    }else{
        printf(" - padre %d\n", getpid());
    }
    return 0;
}