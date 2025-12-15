#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main(){
    int x = 1;
    printf("[P] Valore iniziale di x = %d\n", x);
    int pid = fork();
    if(pid == 0){
        x = x * 2;
        printf("[F] x nel figlo = %d\n", x);
        exit(0);
    }
    wait(NULL);
    printf("[P] x nel padre dopo la terminazione del figlio = %d\n", x);
    return 0;
}

//mi aspetto che il valore di x nel processo padre rimanga invariato a 1,
//mentre nel processo figlio venga modificato a 2.
//perche il figlio e il padre non cndividono lo stesso spazio di memoria.