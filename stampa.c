#include <stdio.h>
#include <stdlib.h>

int* incrementa(){
    int* p = malloc(sizeof(int));
    *p = 10;
    return p;
}

int main(){
    int* k = 0;
    k = incrementa();
    printf("Valore di k: %d\n", *k);
    return 0;
}   