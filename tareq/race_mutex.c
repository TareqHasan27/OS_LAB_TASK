#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared = 1;
pthread_mutex_t l;
int main() {
pthread_mutex_init(&l, NULL);

pthread_t thread1, thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("FINAL VALUE %d\n",shared);
}
void *fun1() {
int x;
printf("thread1 trying to acquire lock\n");
pthread_mutex_lock(&l);

printf("Thread1 acquire lock\n");
x = shared;
printf("thread1 reads value %d\n",x);
x++;
printf("Local updation by thread1 : %d\n", x);
sleep(1);
shared = x;
printf("Value of shared variable by thread1 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread1 realeased the lock\n");
}


void *fun2() {
int x;
printf("thread2 trying to acquire lock\n");
pthread_mutex_lock(&l);

printf("Thread2 acquire lock\n");
x = shared;
printf("thread2 reads value %d\n",x);
x--;
printf("Local updation by thread2 : %d\n", x);
sleep(1);
shared = x;
printf("Value of shared variable by thread2 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread2 realeased the lock\n");
}
