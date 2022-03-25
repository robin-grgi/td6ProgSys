//
// Created by Florian Salord on 28/03/2018.
//
#include <unistd.h>
#include <stdio.h>
#include <memory.h>

void lecture(int fd) {
    char buff[3];
    while (read(fd, buff, 3)) {
        write(STDOUT_FILENO, buff, sizeof(buff));
        printf("\n");
    }
    printf("\n");
}

void writing(int p[2], char *buff, unsigned int sleep_timer) {
    for (int i = 0; i < strlen(buff) / 2; i++) {
        write(p[1], buff, 2);
        buff += 2;
        sleep(sleep_timer);
    }
}

int main() {
    int p[2];
    pipe(p);
    if (fork()) {
        if (fork()) {
            close(p[1]);
            lecture(p[0]);
            close(p[0]);
        } else {
            writing(p, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 2);
        }
    } else {
        writing(p, "abcdefghijklmnopqrstuvwxyz", 1);
    }

    return 0;
}
