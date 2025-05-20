#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("myfile.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        printf("error open\n");
        return 1;
    }
    write(fd, "Hello World\n", 12);
    close(fd);
    return 0;
}

