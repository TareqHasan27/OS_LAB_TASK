#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
int src = open("test.txt",O_RDONLY);
int dest = open("copy.txt",O_CREAT|O_WRONLY,0644);
if(src<0 || dest <0) {
printf("error open\n");
return 1;
}
char buffer[50];
int n;
while((n = read(src, buffer, sizeof(buffer))) > 0)
{
write(dest, buffer, n);
}
close(src);
close(dest);
printf("File copying succesfully\n");
}
