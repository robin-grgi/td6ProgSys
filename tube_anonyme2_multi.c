#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>


void lecture(int fd){
    char msg[3];
    int n;
    while((n = read(fd, msg, 3))){
        if(n == 2){
            printf("%c%c\n", msg[0], msg[1]);
        } else if (n == 3){
            printf("%s\n", msg);
        }
    }
}

int main() {
    int fds[2];
    pipe(fds);

    switch (fork()) {
    case 0:
        switch (fork()) {
        case 0:
            char *minAlphabet = "abcdefghijklmnopqrstuvwxyz";
            for(int i = 0 ; i < 26 ; i += 2) {
                write(fds[1], minAlphabet, 2);
                minAlphabet += 2;
                sleep(2);
            }
            exit(0);
        
        default:
            char *majAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for(int i = 0 ; i < 26 ; i += 2){
                write(fds[1], majAlphabet, 2);
                majAlphabet += 2;
                sleep(1);
            }
            break;
        }    
        break;
    default:
        close(fds[1]);
        lecture(fds[0]);
        close(fds[0]);
    }
    return 0;
}
