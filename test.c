#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    printf("%d\n", pid);
    return 0;
}
