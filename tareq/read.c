#include<unistd.h>
int main()
{
      int n;
      char buff[30];
      n = read(0, buff, 30);
      write(1, buff, n);
}
