#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 1000;
    char* params = (char *)malloc(sizeof(char)*size);
    char* str = "Hey Bro";
    sprintf(params, "A params,  resultParam=%s", str);

    printf("%s", params);

    return 0;
}