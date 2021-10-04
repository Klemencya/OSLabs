#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Input the size of the array: \n");
    scanf ("%d", &n);
    int *array = malloc(n*sizeof(int));
    printf("Array of size %d: ", n);
    for (int i = 0; i < n; i++){
        array[i] = i;
        printf("%d ", array[i]);
    }
    return 0;
}
