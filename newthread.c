#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg){
    printf("thread\n");
        printf("PID: %d\n", getpid());
        printf("id: %lu\n", pthread_self());
    return NULL;
}

int main(){
    printf("main\n");    
    printf("PID: %d\n", getpid());
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("id: %lu\n", pthread_self());
    printf("id new: %lu\n", (unsigned long)thread);
    pthread_join(thread, NULL);
    return 0;
}