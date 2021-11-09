#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdbool.h>

int main(){
    struct input_event event;

    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd",O_RDONLY);
    while (true){
        if (fd!=-1){
            read(fd, &event, sizeof(event));
            switch(event.value){
                case 0:
                    printf ("RELEASED %x, %d \n", event.code, event.code);
                    break;
                case 1:
                    printf ("PRESSED %x, %d \n", event.code, event.code);
                    break;
                default:
                    printf("");
                    break;
            }
        }
    }
}