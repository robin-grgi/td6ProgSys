#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXL 100

void lecture(int fd){
    char msg[MAXL];
    read(fd, msg, MAXL);
    printf("%s\n", msg);
}

int main() {
    int fds[2];
    pipe(fds);

    switch (fork()) {
    case 0:
        close(fds[1]);
        lecture(fds[0]);
        break;
    
    default:
        close(fds[0]);
        write(fds[1], "0123456789", sizeof("0123456789"));
        break;
    }
    return 0;
}
