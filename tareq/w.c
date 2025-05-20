#include<unistd.h>
#include<stdio.h>
int main()
{
      int n;
      char buff[] = "Hello";
      n = write(1,buff,4);
      printf("the value of n is %d\n", n);
}



