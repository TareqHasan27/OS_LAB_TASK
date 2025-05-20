#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("target") < 0) {
         printf("File deleted error\n"); 
       return 1;
    }
    printf("File deleted successfully\n");
    return 0;
}

