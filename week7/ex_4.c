#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void *ptr, size_t previous_size, size_t new_size){
    if (ptr == NULL){
        return malloc(new_size);
    } else if (new_size == 0){
        free(ptr);
    } else if (new_size > previous_size){
        void *temp = malloc(new_size);
        free(ptr);
        return temp;
    } else {
        return ptr;
    }
}

int main() {
    int n1, n2;
    printf("Input the size of the array: ");
    scanf("%d", &n1);
    int* a = malloc(n1*sizeof(int));
    for (int i = 0; i < n1; i++){
        a[i] = 100;
    }
    printf("Input the new size of the array: ");
    scanf("%d", &n2);
    my_realloc(a, n1, n2);

    if (n2 > n1){
        for (int i = n1; i < n2; i++){
            a[i] = 0;
        }
    }
    for (int i = 0; i < n2; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
