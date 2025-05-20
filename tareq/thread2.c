#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int arr[2]={2 , 3};
int main(){
pthread_t a;
void *result;
pthread_create(&a , NULL, thread_function, (void *)arr);
pthread_join(a, &result);
printf("INside the Main Process\n");
printf("THread returned : %s\n",(char *)result);
}
void *thread_function(void *arg) {
printf("inside the thread\n");
int *x = arg;
int sum = x[0] + x[1];
printf("the sum is %d\n", sum);
pthread_exit("Sum Calculated");
}

