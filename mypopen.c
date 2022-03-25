#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    } else {
        int fds[2];
        pipe(fds);
        switch (fork()) {
            case 0:
                close(fds[1]);
                dup2(fds[0], 0);
                close(fds[0]);
                execvp(argv[1], argv+1);
                break;
            default:
                close(fds[0]);
                dup2(fds[1], 1);
                close(fds[1]);
                execlp("cat", "cat", NULL);
                break;
        }
    }
    return 0;
}
