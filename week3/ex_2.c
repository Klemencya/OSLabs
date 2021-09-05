#include <stdio.h>

void bubble_sort(int a[], int n){
    int var;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                var = a[j];
                a[j] = a[j+1];
                a[j+1] = var;
            }
        }
    }
}

int main() {
    int arr[10] = {9, 5, 4, 2, 7, 9, 3, 1, 0, 6};
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
