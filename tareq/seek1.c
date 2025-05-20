#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
     int n , f, f1;
     char buff[20];
     f = open("seeking",O_RDWR);
     lseek(f,-10, SEEK_END);
     n = read(f, buff, 10);
     write(1, buff, n);
}


