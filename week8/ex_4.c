#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <printf.h>

int main() {
    for (int i = 0; i < 10; i++){
        char* data = malloc(10*1024*1024);
        memset(data, '0', 10*1024*1024);
        int who = RUSAGE_SELF;
        struct rusage u;
        int r = getrusage(who, &u);
        printf("Memory usage %lu \n", u.ru_maxrss);
        sleep(1);
    }
    return 0;
}