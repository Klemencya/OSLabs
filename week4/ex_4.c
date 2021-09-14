#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    char str[100];
    printf("MAX LENGTH 100 symbols\n");
    char* arg[10] = {NULL};
    char* token;
    int i = 0;
    pid_t PID;

    while (true){
        printf("Enter command\n");
        scanf("%[^\n]%*c", &str);
        token = strtok(str," \n");
        while (token!=NULL){
            arg[i]=token;
            token = strtok(NULL," \n");
            i++;
        }
        PID = fork();
        if (PID==0) {
            execvp(arg[0], arg);
        } else {
            wait(NULL);
        }
        i = 0;
    }
}