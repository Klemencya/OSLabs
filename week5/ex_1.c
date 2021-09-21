#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <zconf.h>

typedef struct {
    pthread_t thread_id;
    int thread_num;
    char * string;
} thread_info;

void* job(void* args){
    thread_info *t = (thread_info*)args;
    printf("Hello from thread %d\n", t->thread_num);
    return NULL;
}

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    thread_info * tinfo;

    tinfo = calloc(n, sizeof(thread_info));

    for (int i = 0; i < n; i++){
        tinfo[i].thread_num = i;
        printf("Creation of thread %d\n", i);
        pthread_create(&tinfo[i].thread_id, NULL, job, &tinfo[i]);
        printf("Exit of thread %d\n", i);
    }
    for (int i = 0; i < n; i++){
        (void)pthread_join((pthread_t) &tinfo[i], NULL);
    }
    exit(EXIT_SUCCESS);
}
