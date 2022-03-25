#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    //system("cat > /tmp/my_named_pipe");//exemple du cours
    int p = open("/tmp/my_named_pipe", O_WRONLY);
    char buff[BUFFER_SIZE];
    while (fgets(buff, BUFFER_SIZE, stdin)) {
        write(p, buff, strlen(buff));
    }
    close(p);
    
    return 0;
}
