#include <stdio.h>
#include <stdlib.h>

void numeri_pari(){
    for (int i = 0; i < 1000; i+=2){
        printf("%d\n", i);
    }   
    exit(1);
}

void numeri_dispari(){
    for (int i = 1; i < 1000; i+=2){
        printf("%d\n", i);
    }  
    exit(1); 
}

int main(){
    int pid = fork();
    if(pid == 0){
        numeri_pari();
    }else{
        numeri_dispari();
    }

    return 0;
}

