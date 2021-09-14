#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("MAX LENGTH 50 symbols\n");
    char str[50];
    while (true){
        printf("Enter command\n");
        scanf("%s", str);
        system(str);
    }
}
