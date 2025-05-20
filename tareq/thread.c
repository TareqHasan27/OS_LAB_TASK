#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int i , j;
int main() {
pthread_t a_thread;
pthread_create(&a_thread, NULL, thread_function, NULL);
pthread_join(a_thread,NULL);
printf("Inside the main program\n");
for(j = 20; j < 25; j++)
{
printf("%d\n", j);
sleep(1);
}
}
void *thread_function(void *arg){
printf("inside thread\n");
for(int i = 0; i < 5; i++)
{
printf("%d\n", i);
sleep(1);
}
}
