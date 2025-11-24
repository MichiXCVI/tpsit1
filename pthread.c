#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(){
    printf("id: %lu\n", pthread_self());
    return 0;
}