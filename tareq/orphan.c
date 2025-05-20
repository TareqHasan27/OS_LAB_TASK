#include<unistd.h>
#include<stdio.h>
int main(){
      pid_t p;
      p = fork();
      if(p == 0)
      {
            sleep(10);
            printf("I am child having id is %d\n",getpid());
            printf("My parents id is %d\n",getppid());
      }
      else
      {
            sleep(3);
            printf("I am parent having id is %d\n",getpid());
            printf("My child id is %d\n",p);
      }
}

