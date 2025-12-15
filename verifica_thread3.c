#include <stdio.h>
#include <stdlib.h>

int main(){
    int k = 50;
    float *val = malloc((size_t)k * sizeof(float));

    for(int i = 0; i < k; i++){
        val[i] = i;
    }

    printf("inserimento terminato\n");

    for(int i = 0; i < k; i++){
        printf("%f\n", val[i]);
    }
    
    free(val);
    return 0;
}   