#include<unistd.h>
#include<fcntl.h>
int main()
{
    int n, fd, fd1;
    char buff[50];
    //fd = open("test.txt", O_RDONLY);
    n = read(0, buff, 50);
    fd1 = open("target",O_WRONLY);
    write(fd1, buff, n);
}

