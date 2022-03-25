#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    //system("cat < /tmp/my_named_pipe");//exemple du cours
    int p = open("/tmp/my_named_pipe", O_RDONLY);
    char buff[BUFFER_SIZE];
    while (read(p, buff, BUFFER_SIZE)) {
        printf("%s\n", buff);
    }
    close(p);
        
    return 0;
}
