#include <stdio.h>

int main(void)
{
    char msg[] = "HOLa";
    const int a = 5;
    const int *p = &a;

    printf("%s \n", msg);
    return 0;
}