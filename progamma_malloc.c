#include <stdio.h>
#include <stdlib.h>

int main(){
    int k;
    scanf("%d", &k);
    float *val = malloc((size_t)k * sizeof(float));
    for(int i = 0; i < k; i++){
        val[i] = i * 2;
    }
    for(int i = 0; i < k; i++){
        printf("%f\n", val[i]);
    }
    float media;
    for(int i = 0; i < k; i++){
        media += val[i];
    }
    media = media / k;
    printf("\nMedia: %f\n\n", media);
    for(int i = 0; i < k; i++){
        if(val[i] > media){
            printf("%f\n", val[i]);
        }
    }
    free(val);
    return 0;
}   