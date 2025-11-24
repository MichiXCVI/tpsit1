#include <stdio.h>
#include <stdlib.h>

void incrementa(int *valore){
    (*valore)++;
}

int main(){
    int k = 0;
    incrementa(&k);
    printf("Valore di k: %d\n", k);
    return 0;
}   