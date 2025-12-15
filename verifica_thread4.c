#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int thread_function(void *arg)
{
    int *val = (int *)arg;
    int min = 100;

    for (int i = 0; i < 10; i++){
        if (val[i] < min){
            min = val[i];
        }
    }
    
    int *ris = malloc(sizeof(int));
    *ris = min;
    return ris;
}

int thread_function2(void *arg)
{
    int *val = (int *)arg;
    int somma = 0;

    for (int i = 0; i < 10; i++){
        somma += val[i];
    }

    int *ris1 = malloc(sizeof(int));
    *ris1 = somma;
    return ris1;
}

int main()
{
    int *val = malloc(10 * sizeof(int));
    val[0] = 1;
    val[1] = 2;
    val[2] = 3;
    val[3] = 4;
    val[4] = 5;
    val[5] = 10;
    val[6] = 20;
    val[7] = 30;
    val[8] = 40;
    val[9] = 50;
    
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_function, val);
    pthread_create(&t2, NULL, thread_function2, val);
    
    void *ris = NULL;
    void *ris1 = NULL;
    
    pthread_join(t1, &ris);
    pthread_join(t2, &ris1);
    
    int min = ris ? *(int *)ris : 0;
    int somma = ris1 ? *(int *)ris1 : 0;

    printf("Somma totale: %d\n", min + somma);

    free(ris);
    free(ris1);
    free(val);
    return 0;
}