#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char filename[] = "input_ok.txt";

// this method count the number of processes
int number_of_processes(){
    FILE *file;
    char str;
    file = fopen(filename, "r");
    int rows = 0;
    int proc;
    for (str = getc(file); str != EOF; str = getc(file)){
        if (str == '\n'){
            rows ++;
        }
    }
    proc = (rows - 5) / 2;
    fclose(file);
    return proc;
}

// this method count the number of resources
int number_of_resources(){
    FILE *file;
    char str;
    int res = 0;
    file = fopen(filename, "r");
    while (str != '\n') {
        fscanf(file, "%c", &str);
        if (str >= 48 && str <= 57) {
            res++;
        }
    }
    fclose(file);
    return res;
}

int main() {
    int n = number_of_processes();
    int r = number_of_resources();
    FILE *input_file;
    input_file = fopen(filename, "r");
    int *E = malloc(sizeof(int) * r);
    int *A = malloc(sizeof(int) * r);
    int **C = (int**) malloc(sizeof(int*)*n);
    int **R = (int**) malloc(sizeof(int*)*n);

    for (int j = 0; j < r; j++){
        fscanf(input_file, "%d", &E[j]);
    }

    for (int j = 0; j < r; j++){
        fscanf(input_file, "%d", &A[j]);
    }

    for (int i = 0; i < n; i++){
        C[i] = (int*)malloc(sizeof(int)*r);
        for (int j = 0; j < r; j++){
            fscanf(input_file, "%d", &C[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        R[i] = (int*)malloc(sizeof(int)*r);
        for (int j = 0; j < r; j++){
            fscanf(input_file, "%d", &R[i][j]);
        }
    }
    fclose(input_file);

    int *finish = malloc(sizeof(int) * r);
    bool flag = true;
    int *deadlock_pr = malloc(sizeof(int) * n);

    for ( int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // here we will check our processes until we do not find the deadlock
    while(flag) {
        flag = false;
        for(int i = 0; i < n; i++) {
            int c = 0;
            if (finish[i] == 0) {
                for (int j = 0; j < r; j++) {
                    if (R[i][j] <= A[j]) {
                        c++;
                    }
                }
                // if we didn't satisfy this condition =>
                // continue checking or get a deadlock (depends on i and previous value of flag)
                if (c == r) {
                    finish[i] = 1;
                    for (int k = 0; k < r; k++) {
                        A[k] += C[i][k];
                    }
                    flag = true;
                    i = n;
                }
            }
        }
    }
    // collect processes with deadlock
    int j = 0;
    flag = false;
    for(int i = 0; i < n; i++) {
        if (finish[i] == 0) {
            deadlock_pr[j] = i;
            j++;
            flag = true;
        }
    }
    if (flag) {
        printf("Deadlock! The Deadlock process are - ");
        for(int i = 0; i < j; i++) {
            printf("P%d  ", deadlock_pr[i]);
        }
    } else {
        printf("No Deadlock Occur");
    }
    return 0;
}
