#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>

int main() {
    int n = 7;
    for (int i = 0; i < 10; i ++){
        if (fork() == 0){
            printf("Hello from child %d, n = %d\n", getpid(), n);
        } else {
            printf("Hello from parent %d, n = %d\n", getpid(), n);
        }
    }
    return EXIT_SUCCESS;
}

