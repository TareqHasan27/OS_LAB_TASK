#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
     pid_t p ,q , w1;
     int wstatus;
     p = fork();
     if(p < 0)
     {
     printf("error\n");
     return 1;
     }
     else if(p == 0)
     {
      //sleep(3);
      printf("I am first child having id %d\n", getpid());
      printf("My parents id is %d\n", getppid());
     }
     else
     {
     //wait(NULL);
     //w1 = wait(&wstatus);
     //printf("Status is %d\n",WIFEXITED(wstatus));
     //printf("PID of child is %d\n", w1);
     //printf("My child id is %d\n",p);
     //printf("I am parent having id %d\n", getpid());
            q = fork();
           if(q == 0){
           printf("I am second child having id is %d\n",getpid());
           printf("Parents of second id is %d\n", getppid());
           }
           else {
           waitpid(p, NULL, 0);
           printf("I am parent having id is %d\n",getpid());
           printf("MY first child id is %d\n", p);
           printf("My second child is %d\n", q);
           }
     }
     printf("Common for child and parent\n");
 }

