#include <stdio.h>

void swap(int *x, int *y){
    int swaped;
    swaped = *x;
    *x = *y;
    *y = swaped;
}

int main() {
    int a, b;
    printf("Input two integers\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
