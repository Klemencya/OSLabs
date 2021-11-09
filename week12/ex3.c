#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

int main(){
    struct input_event event1;
    struct input_event event2;
    struct input_event event3;

    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event1-kbd",O_RDONLY);
    read(fd, &event2, sizeof(event2));
    read(fd, &event3, sizeof(event3));
    while (1){
        if (fd!=-1){
            read(fd, &event1, sizeof(event1));
            if (event3.value == 2 && event1.value == 2 && event3.code == 25 && event1.code == 18){
                printf(" I passed the Exam!\n");
            }
            if (event2.value == 2 && event3.value == 2 && event1.value == 2 && event2.code == 46 && event3.code == 30 && event1.code == 25){
                printf(" Get some cappuccino!\n");
            }
            if (event3.value == 2 && event1.value == 2 && event3.code == 35 && event1.code == 17){
                printf(" Hello World!\n");
            }
            if (event3.value == 2){
                event2=event3;
            }
            if (event1.value == 2){
                event3=event1;
            }
        }
    }
}