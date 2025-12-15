#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *num){
    int n = *(int *)num;
    for (int i = 0; i < n; i++) {
        printf("%d\n", i+1);
        sleep(1);
    }
    return NULL; 
}

int main(){
    pthread_t thread;
    int num = 10;
    pthread_create(&thread, NULL, thread_function, &num);
    pthread_join(thread, NULL);
    return 0;
}