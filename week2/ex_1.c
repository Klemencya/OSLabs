#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float f = FLT_MAX;
    double b = DBL_MAX;

    printf("The size of integer variable is: %d and value = %d\n", sizeof(a), a );
    printf("The size of float variable is: %d and value = %f\n", sizeof(b), b);
    printf("The size of double variable is: %d and value = %f\n", sizeof(f), f );
}

