#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg){
    while (1)
    {
        printf("thread\n");
        sleep(1);      
    }
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    int a;
    scanf("%d", &a);
    pthread_cancel(thread);
    sleep(5);
    return 0;
}