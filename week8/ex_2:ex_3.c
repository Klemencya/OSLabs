#include <stdlib.h>
#include <zconf.h>
#include <string.h>

//ex2
// What happens with the memory?
// We can see that value of so is increases because we have overflow of our RAM(creation of virtual memory),
// then after some time we can see that si increase, because our RAM becomes free (turn it back to physical memory)

//ex3
// After the running 'top' command
// We can see a small number of running, a lot of sleeping processes and threads.
// Based on this we can say that it happens, because our processes have many threads 

int main() {
    for (int i = 0; i < 10; i++){
        char* data = malloc(10*1024*1024);
        memset(data, '0', 10*1024*1024);
        sleep(1);
    }
    return 0;
}
