#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("foo", O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    dup2(fd, 1);
    close(fd);
    execlp("ls", "ls", "-l", NULL);   
    return 0;
}
