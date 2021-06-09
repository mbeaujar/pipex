#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int pid;

    pid = fork();
    if (pid == 0)
    {
        printf("non\n");
        //exit(0);
    }
    else
    {
        printf("oui\n");
        exit(0);
    }
    printf("ok\n");
    return (0);
}