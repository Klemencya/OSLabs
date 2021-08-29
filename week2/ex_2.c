#include <stdio.h>
#include <string.h>

int main()
{
    char s[50];
    char out[50];
    printf("Input any string: ");
    scanf("%s", s);
    printf("The length of the string is: %d\n", strlen(s));
    for (int i = strlen(s); i >= 0; i--){
        out[strlen(s)-i-1]=s[i];
    }
    printf(out);
}
